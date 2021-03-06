
[getAllPowerSchemes]
measure=plugin
plugin=runCommand
program="powercfg"
parameter="/L"
OutputType=ANSI
;powercfg -restoredefaultschemes resets all power profiles to default values
finishAction=[!commandMeasure getActivePowerScheme run]

[changeValue]
measure=plugin
dynamicVariables=1
plugin=runCommand
;program=""powercfg""
parameter=#execute#
OutputType=ANSI
finishAction=[!commandMeasure parseProfile buildData()][!updateMeasure parseProfile][!commandMeasure parseProfile displayOptionP()]

[getActivePowerScheme]
measure=plugin
plugin=runCommand
program="powercfg"
parameter="/Q"
OutputType=ANSI
finishAction=[!enableMeasure parseProfile][!commandMeasure parseProfile buildData()][!updateMeasure parseProfile]

[parseProfile]
measure=script
scriptfile="#@#powercfg.lua"
dynamicVariables=1
disabled=1
updateDivider=-1

[gCount]
measure=calc
formula=0
dynamicVariables=1

[sCount]
measure=calc
formula=
dynamicVariables=1

[pCount]
measure=calc
formula=
dynamicVariables=1

[activePowerScheme]
measure=string
string=
dynamicVariables=1

[inactiveSchemeName2]
measure=string
string=
dynamicVariables=1

[inactiveSchemeName3]
measure=string
string=
dynamicVariables=1

[inactiveSchemeName4]
measure=string
string=
dynamicVariables=1

[inactiveSchemeName5]
measure=string
string=
dynamicVariables=1

[g1Name]
measure=string
string=
dynamicVariables=1

[g2Name]
measure=string
string=
dynamicVariables=1

[g3Name]
measure=string
string=
dynamicVariables=1

[g4Name]
measure=string
string=
dynamicVariables=1

[g5Name]
measure=string
string=
dynamicVariables=1

[g6Name]
measure=string
string=
dynamicVariables=1

[g7Name]
measure=string
string=
dynamicVariables=1

[g8Name]
measure=string
string=
dynamicVariables=1

[g9Name]
measure=string
string=
dynamicVariables=1

[g10Name]
measure=string
string=
dynamicVariables=1

[g11Name]
measure=string
string=
dynamicVariables=1

[g12Name]
measure=string
string=
dynamicVariables=1

[g13Name]
measure=string
string=
dynamicVariables=1

[g14Name]
measure=string
string=
dynamicVariables=1

[g15Name]
measure=string
string=
dynamicVariables=1

[sCurrent]
measure=calc
format=
dynamicVariables=1

[s1Name]
measure=string
string=
dynamicVariables=1
substitute="Intel(R) Graphics Power Plan":"Intel Graphics Power","hard disk":"HDD","JavaScript":"JS","Maximum":"Max","Minimum":"Min"

[s2Name]
measure=string
string=
dynamicVariables=1
substitute="Intel(R) Graphics Power Plan":"Intel Graphics Power","Maximum":"Max","Minimum":"Min"

[s3Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Minimum":"Min"

[s4Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Minimum":"Min"

[s5Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Minimum":"Min"

[s6Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Minimum":"Min"

[s7Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Minimum":"Min"

[s8Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Minimum":"Min"

[s9Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Minimum":"Min"

[s10Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Minimum":"Min"

[s1Units]
measure=string
string=
dynamicVariables=1
maxValue=1

[s2Units]
measure=string
string=
dynamicVariables=1

[s3Units]
measure=string
string=
dynamicVariables=1

[s4Units]
measure=string
string=
dynamicVariables=1

[s5Units]
measure=string
string=
dynamicVariables=1

[s6Units]
measure=string
string=
dynamicVariables=1

[s7Units]
measure=string
string=
dynamicVariables=1

[s8Units]
measure=string
string=
dynamicVariables=1

[s9Units]
measure=string
string=
dynamicVariables=1

[s10Units]
measure=string
string=
dynamicVariables=1

[s1ACsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s1DCsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s2ACsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s2DCsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s3ACsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s3DCsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s4ACsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s4DCsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s5ACsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s5DCsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s6ACsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s6DCsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s7ACsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s7DCsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s8ACsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s8DCsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s9ACsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s9DCsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s10ACsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[s10DCsetting]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[p1Name]
measure=string
string=
dynamicVariables=1
minValue=0
maxValue=100
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[p2Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[p3Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[p4Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[p5Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[p6Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[p7Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[p8Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[p9Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""

[p10Name]
measure=string
string=
dynamicVariables=1
substitute="Maximum":"Max","Video playback performance bias.":"Performance","Video playback power-saving bias.":"Power-Saving","Optimize video quality":"Optimize Quality","Prevent idling to sleep":"Prevent Sleep","infinite":"∞"," power savings":"","Turn off display":"Display off","Important Wake Timers Only":"Important only","the computer to enter ":"","the computer to ":""
