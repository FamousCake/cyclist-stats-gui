var drawChart = function(containerId, hrmData)
{
    var _ = require('underscore');

    var timestampData = function(startDate, interval, dataArray)
    {
        var outputData = new Array();

        for (var i = 0; i < dataArray.length; i++) {
            var tempDate = new Date(startDate);
            tempDate.setSeconds(tempDate.getSeconds() + i * interval);
            tempDate = Date.UTC(tempDate.getFullYear(), tempDate.getUTCMonth(), tempDate.getDate(), tempDate.getUTCHours(), tempDate.getUTCMinutes(), tempDate.getUTCSeconds());

            outputData.push([tempDate, dataArray[i]]);
        };

        return outputData;
    }


    var stampedHeartRate = timestampData(hrmData.Start, hrmData.Interval, hrmData.HeartRateData);
    var stampedSpeed = timestampData(hrmData.Start, hrmData.Interval, hrmData.SpeedData);
    var stampedCadance = timestampData(hrmData.Start, hrmData.Interval, hrmData.CadanceData);
    var stampedAltitude = timestampData(hrmData.Start, hrmData.Interval, hrmData.AltitudeData);
    var stampedPower = timestampData(hrmData.Start, hrmData.Interval, hrmData.PowerData);

    $(function () {
        $(containerId).highcharts({
            chart: {
                type: 'spline'
            },
            title: {
                text: 'A graph of the selected lap'
            },
            subtitle: {
                text: ''
            },
            xAxis: {
                type: 'datetime',

                title: {
                    text: 'Time Passed'
                }
            },
            yAxis: {
                title: {
                    text: ''
                },
                min: 0
            },
            tooltip: {
                headerFormat: '<b>{series.name}</b><br>',
                pointFormat: '{point.x:%e. %b}: {point.y:.2f} m'
            },

            plotOptions: {
                spline: {
                    marker: {
                        enabled: true
                    }
                }
            },

            series: [
                { 'name': 'HeartRate (BMP)', 'data': stampedHeartRate },
                { 'name': 'Speed (KM\\H)', 'data': stampedSpeed },
                { 'name': 'Cadance (RPM)', 'data': stampedCadance },
                { 'name': 'Altitude (m\\ft)', 'data': stampedAltitude },
                { 'name': 'Power (Wats)', 'data': stampedPower }
            ]
        });
    });
}


/*

[
    [Date.UTC(1970,  9, 27), hrmData.SpeedData[0]],
    [Date.UTC(1970, 10, 10), hrmData.SpeedData[1]],
    [Date.UTC(1970, 10, 18), hrmData.SpeedData[2]],
    [Date.UTC(1970, 11,  2), hrmData.SpeedData[3]],
    [Date.UTC(1970, 11,  9), hrmData.SpeedData[4]],
    [Date.UTC(1970, 11, 16), hrmData.SpeedData[5]],
    [Date.UTC(1970, 11, 28), hrmData.SpeedData[6]],
    [Date.UTC(1971,  0,  1), hrmData.SpeedData[7]],
    [Date.UTC(1971,  0,  8), hrmData.SpeedData[8]],
    [Date.UTC(1971,  0, 12), hrmData.SpeedData[9]],
    [Date.UTC(1971,  0, 27), hrmData.SpeedData[10]]
]

*/