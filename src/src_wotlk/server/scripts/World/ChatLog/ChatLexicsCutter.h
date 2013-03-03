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

#ifndef TRINITY_CHATLEXICSCUTTER_H
#define TRINITY_CHATLEXICSCUTTER_H

typedef std::vector <std::string> LC_AnalogVector;
typedef std::map <std::string, LC_AnalogVector> LC_AnalogMap;
typedef std::set <std::string> LC_LetterSet;
typedef std::vector <LC_LetterSet> LC_WordVector;
typedef std::vector <LC_WordVector> LC_WordList;
typedef std::multimap <std::string, uint32> LC_WordMap;

static int trailingBytesForUTF8[256] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, 3,3,3,3,3,3,3,3,4,4,4,4,5,5,5,5
};

class LexicsCutter
{
protected:
    LC_AnalogMap m_AnalogMap;
    LC_WordList m_WordList;
    LC_WordMap m_WordMap;

    std::string m_sInvalidChars;
    bool m_bIgnoreMiddleSpaces;
    bool m_bIgnoreLetterRepeat;

    void _Trim(std::string& s, const std::string& drop = " ") const;
    bool _CompareWord(const std::string& str, unsigned int pos, LC_WordVector word) const;
    bool _ProcessLine(char* szLine, std::string& sLine) const;

    bool _ReadLetterAnalogs(const std::string& fileName);
    bool _ReadInnormativeWords(const std::string& fileName);
    void _MapInnormativeWords();

public:
    LexicsCutter(const std::string& sAnalogsFileName, const std::string& sInnormativeWordsFileName, bool bIgnoreMiddleSpaces, bool bIgnoreLetterRepeat);

    static bool ReadUTF8(const std::string& in, std::string& out, unsigned int& pos);

    bool CheckLexics(const std::string& phrase);
};

#endif

