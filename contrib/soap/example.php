<?php
/*
 * Copyright (C) Likan Mod   (https://github.com/ChaosDevLikan/)
 * Copyright (C) Prydev      (http://sourceforge.net/projects/prydevserver) 
 * Copyright (C) TrinityCore (http://www.trinitycore.org)
 * Copyright (C) MaNGOS      (http://www.getmangos.com)
 * Copyright (C) ArkCORE     (http://www.arkania.net)
 * Copyright (C) SkyFireEMU  (http://www.projectskyfire.org)
 *
 * World of Warcraft
 * You can edit but you can not delete this copyright.
 * Genesis Emulator - Genesis Database 
 *
 *
 * By Likan Developer Core C++, SQL (FUN, WoTLK, Cata Realm) of Genesis Server
 */

/**
 * MaNGOSsoap client example
 *
 * a simple example how to invoke commands using SOAP
 *
 * Make sure you enabled SOAP in your mangosd.conf!
 *  SOAP.Enabled = 1
 */

/*
 * $username and $password MUST be uppercase
 * account $username needs at least SEC_ADMINISTRATOR
 */
$username = 'ADMINISTRATOR';
$password = 'ADMINISTRATOR';

$host = "localhost";
$soapport = 7878;
$command = "server info";

$client = new SoapClient(NULL,
array(
    "location" => "http://$host:$soapport/",
    "uri" => "urn:MaNGOS",
    "style" => SOAP_RPC,
    'login' => $username,
    'password' => $password
));

try {
    $result = $client->executeCommand(new SoapParam($command, "command"));

    echo "Command succeeded! Output:<br />\n";
    echo $result;
}
catch (Exception $e)
{
    echo "Command failed! Reason:<br />\n";
    echo $e->getMessage();
}
?>
