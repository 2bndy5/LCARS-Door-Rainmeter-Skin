
[GetBaseColor]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\Microsoft\Windows\DWM
RegValue=ColorizationColor
; dynamicVariables=1
onchangeAction=[!UpdateMeasure ScriptConverter]

[WindowsDarkMode]
measure=Plugin
plugin=DarkContextMenu
DarkMode=1
Tooltips=1

;for historic development insight
; [MeasurePaletteRegistry]
; Measure=Plugin
; Plugin=RunCommand
; Parameter=C:\Windows\System32\reg.exe query HKCU\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Accent /v AccentPalette
; OutputType=ANSI
; FinishAction=[!UpdateMeasure "ScriptConverter"][!UpdateMeasuregroup "RandWinColors"][!Update]
; RegExpSubstitute=1
;Substitute="(?siU).*ARY\s*([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..([[:xdigit:]]{6})..":"\1 \2 \3 \4 \5 \6 \7 \8"
;RegEx PATTERN = RR BB GG .. {8}
; Select a palette entry from
; "\1\2\3\4\5\6\7\8"
;\1 = very very bright (Almost white)
;\2 = very bright
;\3 = Highlight active menu Selection
;\4 = Active Window Color
;\5 = brighter BG
;\6 = darker BG
;\7 = much darker BG
;\8 = Magenta (Bright Purple) Possibly for high contrast theme settings

[ScriptConverter]
measure=script
DynamicVariables=1
ScriptFile="#@#Colors.lua"
updateDivider=-1
onupdateaction=[!enableMeasureGroup RandWinColors]

[mRandomPalette1]
measure=calc
dynamicVariables=1
formula=random
updateDivider=20
UpdateRandom=1
UniqueRandom=1
LowBound=2
HighBound=7
RegExpSubstitute=1
Substitute="^1$":"#Palette1#","^2$":"#Palette2#","^3$":"#Palette3#","^4$":"#Palette4#","^5$":"#Palette5#","^6$":"#Palette6#","^7$":"#Palette7#"
group=RandWinColors
disabled=1

[mRandomPalette2]
measure=calc
dynamicVariables=1
formula=random
updateDivider=20
UpdateRandom=1
UniqueRandom=1
LowBound=2
HighBound=7
RegExpSubstitute=1
Substitute="^1$":"#Palette1#","^2$":"#Palette2#","^3$":"#Palette3#","^4$":"#Palette4#","^5$":"#Palette5#","^6$":"#Palette6#","^7$":"#Palette7#"
group=RandWinColors
disabled=1

[mRandomPalette3]
measure=calc
dynamicVariables=1
formula=random
updateDivider=20
UpdateRandom=1
UniqueRandom=1
LowBound=2
HighBound=7
RegExpSubstitute=1
Substitute="^1$":"#Palette1#","^2$":"#Palette2#","^3$":"#Palette3#","^4$":"#Palette4#","^5$":"#Palette5#","^6$":"#Palette6#","^7$":"#Palette7#"
group=RandWinColors
disabled=1

[mRandomPalette4]
measure=calc
dynamicVariables=1
formula=random
updateDivider=20
UpdateRandom=1
UniqueRandom=1
LowBound=2
HighBound=7
RegExpSubstitute=1
Substitute="^1$":"#Palette1#","^2$":"#Palette2#","^3$":"#Palette3#","^4$":"#Palette4#","^5$":"#Palette5#","^6$":"#Palette6#","^7$":"#Palette7#"
group=RandWinColors
disabled=1

[mRandomPalette5]
measure=calc
dynamicVariables=1
formula=random
updateDivider=20
UpdateRandom=1
UniqueRandom=1
LowBound=2
HighBound=7
RegExpSubstitute=1
Substitute="^1$":"#Palette1#","^2$":"#Palette2#","^3$":"#Palette3#","^4$":"#Palette4#","^5$":"#Palette5#","^6$":"#Palette6#","^7$":"#Palette7#"
group=RandWinColors
disabled=1

[mHue]
measure=calc
dynamicVariables=1
formula=#hue# * #TNGcolors# + Sin(#NemesisColors#) - cos(#CustomColors#) * #WinColors# 
onchangeAction=[!updateMeasure ScriptConverter]
