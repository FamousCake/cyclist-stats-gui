var drawChart = function(containerId, hrmData)
{
    var _ = require('underscore');

    var Speed = new Array();

    for (var i = 0; i < hrmData.SpeedData.length ; i++) {


        var tempDate = new Date(hrmData.Start);

        tempDate.setSeconds(tempDate.getSeconds() + i * hrmData.Interval);


        //Date.UTC()
        var blq = Date.UTC(tempDate.getFullYear(), tempDate.getUTCMonth(), tempDate.getDate(), tempDate.getUTCHours(), tempDate.getUTCMinutes(), tempDate.getUTCSeconds());

        //blq = Date.UTC(2014, 10,10, 15, 10)



        Speed.push([blq, hrmData.SpeedData[i]]);

        //console.log(tempDate.setSeconds(tempDate.getSeconds() + i * hrmData.Interval));

        //document.getElementById('main').innerHTML += '<div>' + "/" +tempDate.getUTCDay() + " / " + tempDate.getMonth() + " / " + tempDate.getDay() + " / " + tempDate.getHours() + " / " + tempDate.getSeconds() + '</div>';
        //document.getElementById('main').innerHTML += '<div>' + tempDate.getUTCMinutes() + '</div>';
        //document.getElementById('main').innerHTML += '<div>' + tempDate + '</div>';
    };


    var Power = new Array();

    for (var i = 0; i < hrmData.PowerData.length ; i++) {


        var tempDate = new Date(hrmData.Start);

        tempDate.setSeconds(tempDate.getSeconds() + i * hrmData.Interval);


        //Date.UTC()
        var blq = Date.UTC(tempDate.getFullYear(), tempDate.getUTCMonth(), tempDate.getDate(), tempDate.getUTCHours(), tempDate.getUTCMinutes(), tempDate.getUTCSeconds());

        //blq = Date.UTC(2014, 10,10, 15, 10)



        Power.push([blq, hrmData.PowerData[i]]);

        //console.log(tempDate.setSeconds(tempDate.getSeconds() + i * hrmData.Interval));

        //document.getElementById('main').innerHTML += '<div>' + "/" +tempDate.getUTCDay() + " / " + tempDate.getMonth() + " / " + tempDate.getDay() + " / " + tempDate.getHours() + " / " + tempDate.getSeconds() + '</div>';
        //document.getElementById('main').innerHTML += '<div>' + tempDate.getUTCMinutes() + '</div>';
        //document.getElementById('main').innerHTML += '<div>' + tempDate + '</div>';
    };


    //document.getElementById('main').innerHTML += text;


    $(function () {
        $(containerId).highcharts({
            chart: {
                type: 'spline'
            },
            title: {
                text: 'Snow depth at Vikjafjellet, Norway'
            },
            subtitle: {
                text: 'Irregular time data in Highcharts JS'
            },
            xAxis: {
                type: 'datetime',
                // dateTimeLabelFormats: { // don't display the dummy year
                //     month: '%e. %b',
                //     year: '%b'
                // },
                title: {
                    text: 'Date'
                }
            },
            yAxis: {
                title: {
                    text: 'Snow depth (m)'
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

            series: [{
                name: 'Speed',
                // Define the data points. All series have a dummy year
                // of 1970/71 in order to be compared on the same x axis. Note
                // that in JavaScript, months start at 0 for January, 1 for February etc.
                data: Speed
            }, {
                name: 'Power',
                data: Power
            }]
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