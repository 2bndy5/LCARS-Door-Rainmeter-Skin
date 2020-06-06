; Requires that WeatherComJSONVariables.inc and WeatherComJSONMeasures.inc
; be @Included in the skin before this file.
;
; Icons in #@#Images\MoonPhase are:
; New Moon :        N.png
; Waning Crescent : WNC.png
; Last Quarter :    LQ.png
; Waning Gibbous :  WNG.png
; Full Moon :       F.png
; Waxing Gibbous :  WXG.png
; First Quarter :   FQ.png
; Waxing Crescent : WXC.png
;
; WeatherComJSONMoon.inc by JSMorley
;   from "Weather.com - Parsing the JSON" (https://forum.rainmeter.net/viewtopic.php?f=118&t=34628)
;
; JSON V3 modifications by OnyxBlack
;

; ========================================
; Day 1
; ========================================

[@MoonDay1Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"moonPhase":\s*\[(?:".*",\s*){0}(".*")(?:,|\]).*"moonPhaseDay":\s*\[(?:.*,\s*){0}(.*)(?:,|\]).*"moonriseTimeLocal":\s*\[(?:".*",\s*){0}(".*")(?:,|\]).*"moonsetTimeLocal":\s*\[(?:".*",\s*){0}(".*")(?:,|\]).*
;RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"moonPhase":\s*\[(?:".*",\s*){0}(".*")(?:,|\]).*"moonPhaseCode":\s*\[(?:".*",\s*){0}(".*")(?:,|\]).*"moonriseTimeLocal":\s*\[(?:".*",\s*){0}(".*")(?:,|\]).*"moonsetTimeLocal":\s*\[(?:".*",\s*){0}(".*")(?:,|\]).*

[@MoonDay1PhaseName]
Measure=WebParser
URL=[@MoonDay1Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay1PhaseIcon]
Measure=WebParser
URL=[@MoonDay1Parent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay1RiseTimeStamp]
Measure=WebParser
URL=[@MoonDay1Parent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay1RiseTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay1RiseTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay1RiseTime TimeStamp "[*@MoonDay1RiseTimeStamp*]"][!SetOption @MoonDay1RiseTime Format "#TimeFormat#"]

[@MoonDay1RiseTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay1RiseTimeStamp]
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"
DynamicVariables=1

[@MoonDay1SetTimeStamp]
Measure=WebParser
URL=[@MoonDay1Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay1SetTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay1SetTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay1SetTime TimeStamp "[*@MoonDay1SetTimeStamp*]"][!SetOption @MoonDay1SetTime Format "#TimeFormat#"]

[@MoonDay1SetTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay1SetTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"

; ========================================
; Day 2
; ========================================

[@MoonDay2Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"moonPhase":\s*\[(?:".*",\s*){1}(".*")(?:,|\]).*"moonPhaseDay":\s*\[(?:.*,\s*){1}(.*)(?:,|\]).*"moonriseTimeLocal":\s*\[(?:".*",\s*){1}(".*")(?:,|\]).*"moonsetTimeLocal":\s*\[(?:".*",\s*){1}(".*")(?:,|\]).*

[@MoonDay2PhaseName]
Measure=WebParser
URL=[@MoonDay2Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay2PhaseIcon]
Measure=WebParser
URL=[@MoonDay2Parent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay2RiseTimeStamp]
Measure=WebParser
URL=[@MoonDay2Parent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay2RiseTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay2RiseTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay2RiseTime TimeStamp "[*@MoonDay2RiseTimeStamp*]"][!SetOption @MoonDay2RiseTime Format "#TimeFormat#"]

[@MoonDay2RiseTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay2RiseTimeStamp]
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"
DynamicVariables=1

[@MoonDay2SetTimeStamp]
Measure=WebParser
URL=[@MoonDay2Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay2SetTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay2SetTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay2SetTime TimeStamp "[*@MoonDay2SetTimeStamp*]"][!SetOption @MoonDay2SetTime Format "#TimeFormat#"]

[@MoonDay2SetTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay2SetTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"

; ========================================
; Day 3
; ========================================

[@MoonDay3Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"moonPhase":\s*\[(?:".*",\s*){2}(".*")(?:,|\]).*"moonPhaseDay":\s*\[(?:.*,\s*){2}(.*)(?:,|\]).*"moonriseTimeLocal":\s*\[(?:".*",\s*){2}(".*")(?:,|\]).*"moonsetTimeLocal":\s*\[(?:".*",\s*){2}(".*")(?:,|\]).*

[@MoonDay3PhaseName]
Measure=WebParser
URL=[@MoonDay3Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay3PhaseIcon]
Measure=WebParser
URL=[@MoonDay3Parent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay3RiseTimeStamp]
Measure=WebParser
URL=[@MoonDay3Parent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay3RiseTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay3RiseTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay3RiseTime TimeStamp "[*@MoonDay3RiseTimeStamp*]"][!SetOption @MoonDay3RiseTime Format "#TimeFormat#"]

[@MoonDay3RiseTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay3RiseTimeStamp]
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"
DynamicVariables=1

[@MoonDay3SetTimeStamp]
Measure=WebParser
URL=[@MoonDay3Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay3SetTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay3SetTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay3SetTime TimeStamp "[*@MoonDay3SetTimeStamp*]"][!SetOption @MoonDay3SetTime Format "#TimeFormat#"]

[@MoonDay3SetTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay3SetTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"

; ========================================
; Day 4
; ========================================

[@MoonDay4Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"moonPhase":\s*\[(?:".*",\s*){3}(".*")(?:,|\]).*"moonPhaseDay":\s*\[(?:.*,\s*){3}(.*)(?:,|\]).*"moonriseTimeLocal":\s*\[(?:".*",\s*){3}(".*")(?:,|\]).*"moonsetTimeLocal":\s*\[(?:".*",\s*){3}(".*")(?:,|\]).*

[@MoonDay4PhaseName]
Measure=WebParser
URL=[@MoonDay4Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay4PhaseIcon]
Measure=WebParser
URL=[@MoonDay4Parent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay4RiseTimeStamp]
Measure=WebParser
URL=[@MoonDay4Parent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay4RiseTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay4RiseTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay4RiseTime TimeStamp "[*@MoonDay4RiseTimeStamp*]"][!SetOption @MoonDay4RiseTime Format "#TimeFormat#"]

[@MoonDay4RiseTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay4RiseTimeStamp]
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"
DynamicVariables=1

[@MoonDay4SetTimeStamp]
Measure=WebParser
URL=[@MoonDay4Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay4SetTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay4SetTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay4SetTime TimeStamp "[*@MoonDay4SetTimeStamp*]"][!SetOption @MoonDay4SetTime Format "#TimeFormat#"]

[@MoonDay4SetTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay4SetTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"

; ========================================
; Day 5
; ========================================

[@MoonDay5Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"moonPhase":\s*\[(?:".*",\s*){4}(".*")(?:,|\]).*"moonPhaseDay":\s*\[(?:.*,\s*){4}(.*)(?:,|\]).*"moonriseTimeLocal":\s*\[(?:".*",\s*){4}(".*")(?:,|\]).*"moonsetTimeLocal":\s*\[(?:".*",\s*){4}(".*")(?:,|\]).*

[@MoonDay5PhaseName]
Measure=WebParser
URL=[@MoonDay5Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay5PhaseIcon]
Measure=WebParser
URL=[@MoonDay5Parent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay5RiseTimeStamp]
Measure=WebParser
URL=[@MoonDay5Parent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay5RiseTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay5RiseTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay5RiseTime TimeStamp "[*@MoonDay5RiseTimeStamp*]"][!SetOption @MoonDay5RiseTime Format "#TimeFormat#"]

[@MoonDay5RiseTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay5RiseTimeStamp]
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"
DynamicVariables=1

[@MoonDay5SetTimeStamp]
Measure=WebParser
URL=[@MoonDay5Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay5SetTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay5SetTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay5SetTime TimeStamp "[*@MoonDay5SetTimeStamp*]"][!SetOption @MoonDay5SetTime Format "#TimeFormat#"]

[@MoonDay5SetTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay5SetTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"

; ========================================
; Day 6
; ========================================

[@MoonDay6Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"moonPhase":\s*\[(?:".*",\s*){5}(".*")(?:,|\]).*"moonPhaseDay":\s*\[(?:.*,\s*){5}(.*)(?:,|\]).*"moonriseTimeLocal":\s*\[(?:".*",\s*){5}(".*")(?:,|\]).*"moonsetTimeLocal":\s*\[(?:".*",\s*){5}(".*")(?:,|\]).*

[@MoonDay6PhaseName]
Measure=WebParser
URL=[@MoonDay6Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay6PhaseIcon]
Measure=WebParser
URL=[@MoonDay6Parent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay6RiseTimeStamp]
Measure=WebParser
URL=[@MoonDay6Parent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay6RiseTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay6RiseTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay6RiseTime TimeStamp "[*@MoonDay6RiseTimeStamp*]"][!SetOption @MoonDay6RiseTime Format "#TimeFormat#"]

[@MoonDay6RiseTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay6RiseTimeStamp]
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"
DynamicVariables=1

[@MoonDay6SetTimeStamp]
Measure=WebParser
URL=[@MoonDay6Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay6SetTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay6SetTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay6SetTime TimeStamp "[*@MoonDay6SetTimeStamp*]"][!SetOption @MoonDay6SetTime Format "#TimeFormat#"]

[@MoonDay6SetTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay6SetTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"

; ========================================
; Day 7
; ========================================

[@MoonDay7Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"moonPhase":\s*\[(?:".*",\s*){6}(".*")(?:,|\]).*"moonPhaseDay":\s*\[(?:.*,\s*){6}(.*)(?:,|\]).*"moonriseTimeLocal":\s*\[(?:".*",\s*){6}(".*")(?:,|\]).*"moonsetTimeLocal":\s*\[(?:".*",\s*){6}(".*")(?:,|\]).*

[@MoonDay7PhaseName]
Measure=WebParser
URL=[@MoonDay7Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay7PhaseIcon]
Measure=WebParser
URL=[@MoonDay7Parent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@MoonDay7RiseTimeStamp]
Measure=WebParser
URL=[@MoonDay7Parent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay7RiseTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay7RiseTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay7RiseTime TimeStamp "[*@MoonDay7RiseTimeStamp*]"][!SetOption @MoonDay7RiseTime Format "#TimeFormat#"]

[@MoonDay7RiseTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay7RiseTimeStamp]
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"
DynamicVariables=1

[@MoonDay7SetTimeStamp]
Measure=WebParser
URL=[@MoonDay7Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#
IfMatch=^$
IfMatchAction=[!SetOption @MoonDay7SetTime TimeStamp "[*@CurrentObservationTimeStamp*]"][!SetOption @MoonDay7SetTime Format "N/A"]
IfNotMatchAction=[!SetOption @MoonDay7SetTime TimeStamp "[*@MoonDay7SetTimeStamp*]"][!SetOption @MoonDay7SetTime Format "#TimeFormat#"]

[@MoonDay7SetTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@MoonDay7SetTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"