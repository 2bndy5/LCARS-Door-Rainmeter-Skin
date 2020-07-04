;
; WeatherComJSONMeasures.inc by JSMorley
;   from "Weather.com - Parsing the JSON" (https://forum.rainmeter.net/viewtopic.php?f=118&t=34628)
;
; JSON V3 modifications by OnyxBlack
;
[@EntireSiteSuperParent]
Measure=WebParser
URL=#URLSite#
DecodeCharacterReference=1
ForceReload=1
UpdateRate=#UpdateRate#
UserAgent="Mozilla/5.0 (Linux; Android 10; Pixel 4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.61 Mobile Safari/537.36"
LogSubstringErrors=0
RegExp=(?siU)^(.*)$
StringIndex=1
FinishAction=[!EnableMeasureGroup Parents]
;Debug=2
;Debug2File=#@#EntireSite.txt

; ========================================
; Units of Measure information
; ========================================

[@UnitsParent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3CurrentObservationsUrlConfig":.*units:\s*([meh])

[@UnitsType]
Measure=WebParser
URL=[@UnitsParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@UnitsTemperature]
Measure=WebParser
URL=[@UnitsParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#,"m":"C","e":"F","h":"C"

[@UnitsSpeed]
Measure=WebParser
URL=[@UnitsParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#,"^m$":"km/h","^e$":"mph","^h$":"mph"

[@UnitsDistance]
Measure=WebParser
URL=[@UnitsParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#,"m":"km","e":"mi","h":"mi"

[@UnitsAccumulation]
Measure=WebParser
URL=[@UnitsParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#,"m":"cm","e":"in","h":"cm"

[@UnitsPrecipitation]
Measure=WebParser
URL=[@UnitsParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#,"m":"mm","e":"in","h":"mm"

[@UnitsPressure]
Measure=WebParser
URL=[@UnitsParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#,"m":"mb","e":"in","h":"mb"

; =========================================
; Location information
; =========================================

[@LocationParent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3LocationPointUrlConfig":.*language:(.*)[;"].*"latitude":(.*),.*"longitude":(.*),.*"adminDistrict":(.*),.*"adminDistrictCode":(.*),.*"country":(.*),.*"countryCode":(.*),.*"displayName":(.*),

[@LocationLanguageCode]
Measure=WebParser
URL=[@LocationParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@LocationLatitude]
Measure=WebParser
URL=[@LocationParent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@LocationLongitude]
Measure=WebParser
URL=[@LocationParent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@LocationAdminDistrict]
Measure=WebParser
URL=[@LocationParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@LocationAdminDistrictCode]
Measure=WebParser
URL=[@LocationParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@LocationCountry]
Measure=WebParser
URL=[@LocationParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@LocationCountryCode]
Measure=WebParser
URL=[@LocationParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@LocationName]
Measure=WebParser
URL=[@LocationParent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@LocationTimezoneParent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3CurrentDateTimeByGeocodeUrlConfig":.*"timeZoneAbbreviation":"(.*)"

[@LocationTimeZoneAbbreviation]
Measure=WebParser
URL=[@LocationTimezoneParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; =============================================
; Current Conditions as of the Observation Time
; =============================================

[@CurrentConditionsParent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3CurrentObservationsUrlConfig":.*"cloudCoverPhrase":(.*),.*"iconCode":(.*),.*"precip24Hour":(.*),.*"pressureAltimeter":(.*),.*"pressureChange":(.*),.*"pressureTendencyCode":(.*),.*"pressureTendencyTrend":(.*),.*"relativeHumidity":(.*),.*"sunriseTimeLocal":(.*),.*"sunsetTimeLocal":(.*),.*"temperature":(.*),.*"temperatureDewPoint":(.*),.*"temperatureFeelsLike":(.*),.*"temperatureMaxSince7AM":(.*),.*"uvDescription":(.*),.*"uvIndex":(.*),.*"validTimeLocal":(.*),.*"visibility":(.*),.*"windDirection":(.*),.*"windDirectionCardinal":(.*),.*"windGust":(.*),.*"windSpeed":(.*),
FinishAction=[!EnableMeasureGroup "Times"]

[@CurrentConditions]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentIcon]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=2
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentPrecipitationLast24Hours]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=3
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentPressure]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentPressureChangeAmount]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentPressureCode]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentPressureChangeTrend]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentHumidity]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=8
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentSunriseTimeStamp]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentSunriseTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@CurrentSunriseTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"

[@CurrentSunSetTimeStamp]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentSunsetTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@CurrentSunsetTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"

[@CurrentTemperature]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentDewPoint]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=12
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentFeelsLike]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=13
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentTemperatureMaxSince7AM]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=14
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentUVDescription]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=15
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentUVIndex]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=16
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentObservationTimeStamp]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=17
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentObservationDate]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@CurrentObservationTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#DateFormat#

[@CurrentObservationTime]
Measure=Time
Group=Times
Disabled=1
TimeStamp=[@CurrentObservationTimeStamp]
DynamicVariables=1
TimeStampFormat=%Y-%m-%dT%H:%M:%S
Format=#TimeFormat#
Substitute="AM":"am","PM":"pm"

[@CurrentVisibilityDistance]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=18
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentWindDirectionDegrees]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=19
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentWindDirectionCompass]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=20
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentWindGust]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=21
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@CurrentWindSpeed]
Measure=WebParser
URL=[@CurrentConditionsParent]
StringIndex=22
RegExpSubstitute=1
Substitute=#CommonSubstitute#

; ========================================
; Forecasts for today and following 6 days
; ========================================

[@ForecastTodayParent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*dayOfWeek":\s*\[(?:".*",\s*){0}(".*").*"cloudCover":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"dayPartName":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"iconCode":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"narrative":\s*\[(?:null,\s*|".*",\s*){0}(null|".*"),\s*(null|".*")(?:,|\]).*"precipChance":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"precipType":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"qpf":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"relativeHumidity":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"snowRange":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"temperature":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"uvDescription":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"uvIndex":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"windDirection":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"windDirectionCardinal":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"windSpeed":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*"wxPhraseLong":\s*\[(?:.*,\s*){0}(.*),\s*(.*)(?:,|\]).*

; ========================================
; Forecasts for today day and night
; ========================================

[@ForecastTodayDayLong]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayShort]
Measure=Time
TimeStamp=[@CurrentObservationTime:TimeStamp]
DynamicVariables=1
FormatLocale=#Language#
Format=%a

[@ForecastTodayDayCloudPercent]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=2
RegExpSubstitute=1
MinValue=0
MaxValue=100
Substitute=#CommonSubstitute#

[@ForecastTodayNightCloudPercent]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=3
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayPart]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightPart]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayIcon]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightIcon]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayNarrative]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightNarrative]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayPrecipitationPercent]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightPrecipitationPercent]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayPrecipitationType]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=12
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightPrecipitationType]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=13
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayPrecipitationAmount]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=14
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightPrecipitationAmount]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=15
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayHumidity]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=16
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightHumidity]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=17
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDaySnowRange]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=18
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightSnowRange]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=19
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayTemperature]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=20
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightTemperature]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=21
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayUVIndexDescription]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=22
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightUVIndexDescription]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=23
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayUVIndex]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=24
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightUVIndex]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=25
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=26
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=27
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayWindDirectionCompass]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=28
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightWindDirectionCompass]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=29
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayWindSpeed]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=30
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightWindSpeed]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=31
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayDayConditions]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=32
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayNightConditions]
Measure=WebParser
URL=[@ForecastTodayParent]
StringIndex=33
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastTodayMonthLong]
Measure=Time
TimeStamp=[@CurrentObservationTime:TimeStamp]
DynamicVariables=1
FormatLocale=#Language#
Format=%B

[@ForecastTodayMonthShort]
Measure=Time
TimeStamp=[@CurrentObservationTime:TimeStamp]
DynamicVariables=1
FormatLocale=#Language#
Format=%b

[@ForecastTodayDayOfMonth]
Measure=Time
TimeStamp=[@CurrentObservationTime:TimeStamp]
DynamicVariables=1
FormatLocale=#Language#
Format=%#d

; ========================================
; Forecasts for Day 2 day and night
; ========================================

[@ForecastDay2Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"dayOfWeek":\s*\[(?:".*",\s*){1}(".*").*"cloudCover":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"dayPartName":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"iconCode":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"narrative":\s*\[(?:null,\s*|".*",\s*){2}(null|".*"),\s*(null|".*")(?:,|\]).*"precipChance":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"precipType":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"qpf":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"relativeHumidity":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"snowRange":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"temperature":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"uvDescription":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"uvIndex":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"windDirection":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"windDirectionCardinal":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"windSpeed":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*"wxPhraseLong":\s*\[(?:.*,\s*){2}(.*),\s*(.*)(?:,|\]).*

[@ForecastDay2DayLong]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 1))
DynamicVariables=1
FormatLocale=#Language#
Format=%a

[@ForecastDay2DayCloudPercent]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=2
RegExpSubstitute=1
MinValue=0
MaxValue=100
Substitute=#CommonSubstitute#

[@ForecastDay2NightCloudPercent]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=3
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayPart]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightPart]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayIcon]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightIcon]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayNarrative]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightNarrative]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayPrecipitationType]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=12
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightPrecipitationType]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=13
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=14
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=15
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayHumidity]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=16
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightHumidity]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=17
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DaySnowRange]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=18
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightSnowRange]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=19
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayTemperature]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=20
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightTemperature]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=21
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=22
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=23
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayUVIndex]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=24
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightUVIndex]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=25
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=26
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=27
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=28
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=29
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayWindSpeed]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=30
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightWindSpeed]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=31
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2DayConditions]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=32
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2NightConditions]
Measure=WebParser
URL=[@ForecastDay2Parent]
StringIndex=33
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay2MonthLong]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 1))
DynamicVariables=1
FormatLocale=#Language#
Format=%B

[@ForecastDay2MonthShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 1))
DynamicVariables=1
FormatLocale=#Language#
Format=%b

[@ForecastDay2DayOfMonth]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 1))
DynamicVariables=1
FormatLocale=#Language#
Format=%#d

; ========================================
; Forecasts for Day 3 day and night
; ========================================

[@ForecastDay3Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"dayOfWeek":\s*\[(?:".*",\s*){2}(".*").*"cloudCover":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"dayPartName":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"iconCode":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"narrative":\s*\[(?:null,\s*|".*",\s*){4}(null|".*"),\s*(null|".*")(?:,|\]).*"precipChance":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"precipType":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"qpf":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"relativeHumidity":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"snowRange":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"temperature":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"uvDescription":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"uvIndex":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"windDirection":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"windDirectionCardinal":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"windSpeed":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*"wxPhraseLong":\s*\[(?:.*,\s*){4}(.*),\s*(.*)(?:,|\]).*

[@ForecastDay3DayLong]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 2))
DynamicVariables=1
FormatLocale=#Language#
Format=%a

[@ForecastDay3DayCloudPercent]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=2
RegExpSubstitute=1
MinValue=0
MaxValue=100
Substitute=#CommonSubstitute#

[@ForecastDay3NightCloudPercent]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=3
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayPart]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightPart]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayIcon]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightIcon]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayNarrative]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightNarrative]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayPrecipitationType]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=12
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightPrecipitationType]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=13
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=14
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=15
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayHumidity]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=16
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightHumidity]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=17
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DaySnowRange]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=18
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightSnowRange]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=19
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayTemperature]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=20
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightTemperature]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=21
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=22
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=23
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayUVIndex]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=24
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightUVIndex]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=25
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=26
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=27
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=28
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=29
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayWindSpeed]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=30
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightWindSpeed]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=31
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3DayConditions]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=32
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3NightConditions]
Measure=WebParser
URL=[@ForecastDay3Parent]
StringIndex=33
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay3MonthLong]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 2))
DynamicVariables=1
FormatLocale=#Language#
Format=%B

[@ForecastDay3MonthShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 2))
DynamicVariables=1
FormatLocale=#Language#
Format=%b

[@ForecastDay3DayOfMonth]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 2))
DynamicVariables=1
FormatLocale=#Language#
Format=%#d

; ========================================
; Forecasts for Day 4 day and night
; ========================================

[@ForecastDay4Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"dayOfWeek":\s*\[(?:".*",\s*){3}(".*").*"cloudCover":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"dayPartName":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"iconCode":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"narrative":\s*\[(?:null,\s*|".*",\s*){6}(null|".*"),\s*(null|".*")(?:,|\]).*"precipChance":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"precipType":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"qpf":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"relativeHumidity":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"snowRange":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"temperature":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"uvDescription":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"uvIndex":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"windDirection":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"windDirectionCardinal":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"windSpeed":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*"wxPhraseLong":\s*\[(?:.*,\s*){6}(.*),\s*(.*)(?:,|\]).*

[@ForecastDay4DayLong]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 3))
DynamicVariables=1
FormatLocale=#Language#
Format=%a

[@ForecastDay4DayCloudPercent]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=2
RegExpSubstitute=1
MinValue=0
MaxValue=100
Substitute=#CommonSubstitute#

[@ForecastDay4NightCloudPercent]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=3
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayPart]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightPart]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayIcon]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightIcon]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayNarrative]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightNarrative]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayPrecipitationType]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=12
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightPrecipitationType]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=13
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=14
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=15
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayHumidity]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=16
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightHumidity]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=17
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DaySnowRange]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=18
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightSnowRange]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=19
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayTemperature]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=20
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightTemperature]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=21
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=22
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=23
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayUVIndex]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=24
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightUVIndex]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=25
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=26
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=27
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=28
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=29
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayWindSpeed]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=30
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightWindSpeed]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=31
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4DayConditions]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=32
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4NightConditions]
Measure=WebParser
URL=[@ForecastDay4Parent]
StringIndex=33
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay4MonthLong]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 3))
DynamicVariables=1
FormatLocale=#Language#
Format=%B

[@ForecastDay4MonthShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 3))
DynamicVariables=1
FormatLocale=#Language#
Format=%b

[@ForecastDay4DayOfMonth]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 3))
DynamicVariables=1
FormatLocale=#Language#
Format=%#d

; ========================================
; Forecasts for Day 5 day and night
; ========================================

[@ForecastDay5Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"dayOfWeek":\s*\[(?:".*",\s*){4}(".*").*"cloudCover":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"dayPartName":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"iconCode":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"narrative":\s*\[(?:null,\s*|".*",\s*){8}(null|".*"),\s*(null|".*")(?:,|\]).*"precipChance":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"precipType":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"qpf":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"relativeHumidity":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"snowRange":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"temperature":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"uvDescription":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"uvIndex":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"windDirection":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"windDirectionCardinal":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"windSpeed":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*"wxPhraseLong":\s*\[(?:.*,\s*){8}(.*),\s*(.*)(?:,|\]).*

[@ForecastDay5DayLong]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 4))
DynamicVariables=1
FormatLocale=#Language#
Format=%a

[@ForecastDay5DayCloudPercent]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=2
RegExpSubstitute=1
MinValue=0
MaxValue=100
Substitute=#CommonSubstitute#

[@ForecastDay5NightCloudPercent]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=3
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayPart]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightPart]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayIcon]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightIcon]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayNarrative]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightNarrative]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayPrecipitationType]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=12
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightPrecipitationType]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=13
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=14
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=15
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayHumidity]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=16
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightHumidity]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=17
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DaySnowRange]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=18
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightSnowRange]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=19
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayTemperature]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=20
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightTemperature]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=21
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=22
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=23
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayUVIndex]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=24
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightUVIndex]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=25
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=26
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=27
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=28
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=29
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayWindSpeed]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=30
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightWindSpeed]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=31
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5DayConditions]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=32
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5NightConditions]
Measure=WebParser
URL=[@ForecastDay5Parent]
StringIndex=33
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay5MonthLong]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 4))
DynamicVariables=1
FormatLocale=#Language#
Format=%B

[@ForecastDay5MonthShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 4))
DynamicVariables=1
FormatLocale=#Language#
Format=%b

[@ForecastDay5DayOfMonth]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 4))
DynamicVariables=1
FormatLocale=#Language#
Format=%#d

; ========================================
; Forecasts for Day 6 day and night
; ========================================

[@ForecastDay6Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"dayOfWeek":\s*\[(?:".*",\s*){5}(".*").*"cloudCover":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"dayPartName":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"iconCode":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"narrative":\s*\[(?:null,\s*|".*",\s*){10}(null|".*"),\s*(null|".*")(?:,|\]).*"precipChance":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"precipType":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"qpf":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"relativeHumidity":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"snowRange":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"temperature":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"uvDescription":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"uvIndex":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"windDirection":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"windDirectionCardinal":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"windSpeed":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*"wxPhraseLong":\s*\[(?:.*,\s*){10}(.*),\s*(.*)(?:,|\]).*

[@ForecastDay6DayLong]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 5))
DynamicVariables=1
FormatLocale=#Language#
Format=%a

[@ForecastDay6DayCloudPercent]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=2
RegExpSubstitute=1
MinValue=0
MaxValue=100
Substitute=#CommonSubstitute#

[@ForecastDay6NightCloudPercent]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=3
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayPart]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightPart]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayIcon]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightIcon]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayNarrative]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightNarrative]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayPrecipitationType]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=12
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightPrecipitationType]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=13
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=14
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=15
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayHumidity]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=16
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightHumidity]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=17
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DaySnowRange]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=18
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightSnowRange]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=19
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayTemperature]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=20
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightTemperature]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=21
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=22
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=23
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayUVIndex]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=24
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightUVIndex]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=25
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=26
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=27
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=28
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=29
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayWindSpeed]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=30
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightWindSpeed]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=31
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6DayConditions]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=32
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6NightConditions]
Measure=WebParser
URL=[@ForecastDay6Parent]
StringIndex=33
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay6MonthLong]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 5))
DynamicVariables=1
FormatLocale=#Language#
Format=%B

[@ForecastDay6MonthShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 5))
DynamicVariables=1
FormatLocale=#Language#
Format=%b

[@ForecastDay6DayOfMonth]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 5))
DynamicVariables=1
FormatLocale=#Language#
Format=%#d

; ========================================
; Forecasts for Day 7 day and night
; ========================================

[@ForecastDay7Parent]
Measure=WebParser
Group=Parents
URL=[@EntireSiteSuperParent]
Disabled=1
StringIndex=1
RegExp=(?siU)"getSunV3DailyForecastUrlConfig":.*"dayOfWeek":\s*\[(?:".*",\s*){6}(".*").*"cloudCover":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"dayPartName":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"iconCode":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"narrative":\s*\[(?:null,\s*|".*",\s*){12}(null|".*"),\s*(null|".*")(?:,|\]).*"precipChance":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"precipType":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"qpf":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"relativeHumidity":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"snowRange":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"temperature":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"uvDescription":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"uvIndex":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"windDirection":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"windDirectionCardinal":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"windSpeed":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*"wxPhraseLong":\s*\[(?:.*,\s*){12}(.*),\s*(.*)(?:,|\]).*

[@ForecastDay7DayLong]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=1
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 6))
DynamicVariables=1
FormatLocale=#Language#
Format=%a

[@ForecastDay7DayCloudPercent]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=2
RegExpSubstitute=1
MinValue=0
MaxValue=100
Substitute=#CommonSubstitute#

[@ForecastDay7NightCloudPercent]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=3
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayPart]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=4
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightPart]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=5
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayIcon]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=6
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightIcon]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=7
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayNarrative]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=8
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightNarrative]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=9
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightPrecipitationPercent]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=11
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayPrecipitationType]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=12
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightPrecipitationType]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=13
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=14
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightPrecipitationAmount]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=15
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayHumidity]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=16
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightHumidity]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=17
MinValue=0
MaxValue=100
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DaySnowRange]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=18
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightSnowRange]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=19
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayTemperature]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=20
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightTemperature]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=21
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=22
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightUVIndexDescription]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=23
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayUVIndex]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=24
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightUVIndex]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=25
MinValue=0
MaxValue=10
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=26
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightWindDirectionDegrees]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=27
MinValue=0
MaxValue=360
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=28
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightWindDirectionCompass]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=29
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayWindSpeed]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=30
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightWindSpeed]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=31
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7DayConditions]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=32
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7NightConditions]
Measure=WebParser
URL=[@ForecastDay7Parent]
StringIndex=33
RegExpSubstitute=1
Substitute=#CommonSubstitute#

[@ForecastDay7MonthLong]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 6))
DynamicVariables=1
FormatLocale=#Language#
Format=%B

[@ForecastDay7MonthShort]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 6))
DynamicVariables=1
FormatLocale=#Language#
Format=%b

[@ForecastDay7DayOfMonth]
Measure=Time
TimeStamp=([@CurrentObservationTime:TimeStamp] + (86400 * 6))
DynamicVariables=1
FormatLocale=#Language#
Format=%#d