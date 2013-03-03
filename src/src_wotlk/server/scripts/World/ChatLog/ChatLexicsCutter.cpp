/*
 * Copyright (C) Likan Mod 2012-2013 <https://github.com/ChaosDevLikan/>
 * Copyright (C) 3server 2005-2013 <https://cata.3server>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "ChatLexicsCutter.h"

LexicsCutter::LexicsCutter(const std::string& sAnalogsFileName, const std::string& sInnormativeWordsFileName, bool bIgnoreMiddleSpaces, bool bIgnoreLetterRepeat)
    : m_sInvalidChars("~`!@#$%^&*()-_+=[{]}|\\;:'\",<.>/?"), m_bIgnoreMiddleSpaces(bIgnoreMiddleSpaces), m_bIgnoreLetterRepeat(bIgnoreLetterRepeat)
{
    if (!_ReadLetterAnalogs(sAnalogsFileName))
        sLog->outError("CHAT LOG: Unable to open file with letter analogs '%s'", sAnalogsFileName);
    if (!_ReadInnormativeWords(sInnormativeWordsFileName))
        sLog->outError("CHAT LOG: Unable to open file with innormative words '%s'", sInnormativeWordsFileName);
    _MapInnormativeWords();
}

bool LexicsCutter::ReadUTF8(const std::string& in, std::string& out, unsigned int& pos)
{
    if (pos >= in.length())
        return false;

    out = "";
    unsigned char c = in[pos++];
    out += c;
    int toread = trailingBytesForUTF8[(int) c];
    while ((pos < in.length()) && (toread > 0))
    {
        out += in[pos++];
        --toread;
    }

    return true;
}

inline void LexicsCutter::_Trim(std::string& s, const std::string& drop) const
{
    s.erase(s.find_last_not_of(drop) + 1);
    s.erase(0, s.find_first_not_of(drop));
}

bool LexicsCutter::_ProcessLine(char* szLine, std::string& sLine) const
{
    // Check for UTF8 prefix and comments
    if (strlen(szLine) >= 3)
        if (szLine[0] == '\xEF' && szLine[1] == '\xBB' && szLine[2] == '\xBF')
            strncpy(&szLine[0], &szLine[3], strlen(szLine) - 3);

    if (strlen(szLine) >= 2)
        if (szLine[0] == '/' && szLine[1] == '/')
            return false;

    // Check for empty string
    sLine = szLine;
    _Trim(sLine, "\x0A\x0D\x20");
    if (sLine.empty())
        return false;

    // Process line without CR/LF
    sLine = szLine;
    _Trim(sLine, "\x0A\x0D");
    return true;
}

bool LexicsCutter::_ReadLetterAnalogs(const std::string& fileName)
{
    char szLine[1024];

    FILE* file = fopen(fileName.c_str(), "rb");
    if (!file)
        return false;

    while (!feof(file))
    {
        szLine[0] = 0x0;
        fgets(szLine, 1020, file);

        std::string sLine;
        if (!_ProcessLine(szLine, sLine))
            continue;

        std::string sChar;
        unsigned int pos = 0;
        if (ReadUTF8(sLine, sChar, pos))
        {
            // Create analogs vector
            std::string sAnalog;
            LC_AnalogVector av;
            while (ReadUTF8(sLine, sAnalog, pos))
                av.push_back(sAnalog);

            // Store vector in hash map
            m_AnalogMap[sChar] = av;
        }
    }
    fclose(file);
    return true;
}

bool LexicsCutter::_ReadInnormativeWords(const std::string& fileName)
{
    char szLine[1024];

    FILE* file = fopen(fileName.c_str(), "rb");
    if (!file)
        return false;

    while (!feof(file))
    {
        szLine[0] = 0x0;
        fgets(szLine, 1020, file);

        std::string sLine;
        if (!_ProcessLine(szLine, sLine))
            continue;

        // Create word vector of vectors
        LC_WordVector vw;
        std::string sChar;
        unsigned int pos = 0;
        while (ReadUTF8(sLine, sChar, pos))
        {
            LC_LetterSet vl;

            // Initialize letter set with letter read
            vl.insert(sChar);

            // Find letter analogs and push them onto the vector
            LC_AnalogMap::iterator itr = m_AnalogMap.find(sChar);
            if (itr != m_AnalogMap.end())
                // Analogs present, iterate
                for (LC_AnalogVector::iterator itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++)
                    vl.insert(*itr2);

            // Add letter vector to word vector
            vw.push_back(vl);
        }

        // Push new word to words list
        m_WordList.push_back(vw);
    }
    fclose(file);
    return true;
}

void LexicsCutter::_MapInnormativeWords()
{
    // Process all the words in the vector
    for (uint32 i = 0; i < m_WordList.size(); ++i)
        // Parse all analogs in the first word letter
        for (LC_LetterSet::iterator itr = (*m_WordList[i].begin()).begin(); itr != (*m_WordList[i].begin()).end(); ++itr)
            // Map the word to its first letter variants
            m_WordMap.insert(std::pair <std::string, uint32> (*itr, i));
}

bool LexicsCutter::_CompareWord(const std::string& str, unsigned int pos, LC_WordVector word) const
{
    std::string sCharPrev;
    std::string sChar;

    // Read first letter of the word into lchar_prev
    ReadUTF8(str, sChar, pos);

    // Compare word
    // First letter is already okay, we do begin from second and go on
    LC_WordVector::iterator i = word.begin();
    i++;
    while (i != word.end())
    {
        // Get letter from word, return false if the string is shorter
        if (!ReadUTF8(str, sChar, pos))
            return false;
        // Check, if the letter is in the set
        LC_LetterSet ls = *i;
        if (ls.count(sChar) == 0)
        {
            // Letter is not in set, but we must check, if it is not space or repeat
            if ((!(m_bIgnoreMiddleSpaces && (sChar == " "))) &&
                (!(m_bIgnoreLetterRepeat && (sChar == sCharPrev))))
            {
                // No checks viable
                return false;
            }
        }
        else
            // Next word letter
            i++;

        // Set previous string letter to compare if needed (this check can really conserve time)
        if (m_bIgnoreLetterRepeat)
            sCharPrev = sChar;
    }
    return true;
}

bool LexicsCutter::CheckLexics(const std::string& msg)
{
    std::string sChar;
    LC_WordMap::iterator i;
    std::pair<LC_WordMap::iterator, LC_WordMap::iterator> ii;

    if (msg.size() == 0)
        return false;

    // Remove links |cffffffff|H<entity>:<id>|h[<name>]|h|r
    std::string s(msg);
    unsigned int offset = 0;
    unsigned int start = -1;
    while ((start = s.find("|cffffffff|H", offset)) != -1)
    {
        unsigned int end = s.find("|h|r", start);
        if (end == -1)
            break;

        s = s.replace(start, end + 4 - start, "");
        offset = start;
    }

    // First, convert the string, adding spaces and removing invalid characters.
    // Also create fast position vector for the new positions
    std::string str(" ");
    unsigned int pos = 0;
    while (ReadUTF8(s, sChar, pos))
        if (m_sInvalidChars.find(sChar) == std::string::npos)
            str.append(sChar);

    // String prepared, now parse it and scan for all the words
    unsigned int pos_prev = 0;
    pos = 0;
    while (ReadUTF8(str, sChar, pos))
    {
        // Got character, now try to find wordmap for it
        ii = m_WordMap.equal_range(sChar);
        // Iterate over all found words
        for (i = ii.first; i != ii.second; i++)
            // Compare word at initial position
            if (_CompareWord(str, pos_prev, m_WordList[i->second]))
                return true;
        // Set initial position to the current position
        pos_prev = pos;
    }
    return false;
}
