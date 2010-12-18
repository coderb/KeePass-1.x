; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=KeePass Password Safe
AppVerName=KeePass Password Safe 0.87
AppPublisher=ReichlSoft
AppPublisherURL=http://keepass.sourceforge.net
AppSupportURL=http://keepass.sourceforge.net
AppUpdatesURL=http://keepass.sourceforge.net
DefaultDirName={pf}\KeePass Password Safe
DefaultGroupName=KeePass Password Safe
AllowNoIcons=yes
LicenseFile=C:\Programme\DevStudio\MyProjects\Security\PwSafe\Ext\Install\License.txt

[Tasks]
; NOTE: The following entry contains English phrases ("Create a desktop icon" and "Additional icons"). You are free to translate them into another language if required.
Name: "desktopicon"; Description: "Create a &desktop icon"; GroupDescription: "Additional icons:"
; NOTE: The following entry contains English phrases ("Create a Quick Launch icon" and "Additional icons"). You are free to translate them into another language if required.
Name: "quicklaunchicon"; Description: "Create a &Quick Launch icon"; GroupDescription: "Additional icons:"; Flags: unchecked

[Files]
Source: "C:\Programme\DevStudio\MyProjects\Security\PwSafe\Distrib\KeePass.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Programme\DevStudio\MyProjects\Security\PwSafe\Distrib\KeePass.html"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Programme\DevStudio\MyProjects\Security\PwSafe\Distrib\KeePass.ini"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Programme\DevStudio\MyProjects\Security\PwSafe\Distrib\License.html"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[INI]
Filename: "{app}\KeePass.url"; Section: "InternetShortcut"; Key: "URL"; String: "http://keepass.sourceforge.net"

[Icons]
Name: "{group}\KeePass Password Safe"; Filename: "{app}\KeePass.exe"
; NOTE: The following entry contains an English phrase ("on the Web"). You are free to translate it into another language if required.
Name: "{group}\KeePass Password Safe on the Web"; Filename: "{app}\KeePass.url"
; NOTE: The following entry contains an English phrase ("Uninstall"). You are free to translate it into another language if required.
Name: "{group}\Uninstall KeePass Password Safe"; Filename: "{uninstallexe}"
Name: "{userdesktop}\KeePass Password Safe"; Filename: "{app}\KeePass.exe"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\KeePass Password Safe"; Filename: "{app}\KeePass.exe"; Tasks: quicklaunchicon

[Run]
; NOTE: The following entry contains an English phrase ("Launch"). You are free to translate it into another language if required.
Filename: "{app}\KeePass.exe"; Description: "Launch KeePass Password Safe"; Flags: nowait postinstall skipifsilent

[UninstallDelete]
Type: files; Name: "{app}\KeePass.url"
