var module = function(filepath, callback) {

    var _ = require('underscore');
    var addon = require('bindings')('addon.node');

    var hrmData = addon(filepath);

    document.getElementById('main').innerHTML = '';
    var text = '';

    text += '<div> The software version is : ' + hrmData.Version + '</div>';
    text += '<div> The monitor is : ' + hrmData.Monitor + '</div>';

    text += '<div> The date is : ' + hrmData.Date + '</div>';
    text += '<div> The starting time is : ' + hrmData.StartTime + '</div>';

    document.getElementById('main').innerHTML += text;

    // document.getElementById('main').innerHTML = '';

    // var text = '';

    // text += '<div> Average heart rate is : ' + (hrmData.HeartRate / hrmData.Count).toFixed(2) + ' BPM </div>';
    // text += '<div> Average speed is : ' + (hrmData.Speed / hrmData.Count).toFixed(2) + ' KM/H </div>';
    // text += '<div> Average cadence is : ' + (hrmData.Cadance / (hrmData.Count * 10)).toFixed(2) + ' RPM </div>';

    // text += '<div> Average altitude is : ' + (hrmData.Altitude / hrmData.Count).toFixed(2) + ' feet </div>';
    // text += '<div> Average power is : ' + (hrmData.Power / hrmData.Count).toFixed(2) + ' W </div>';
    // text += '<div> Average power balance is : ' + (hrmData.PowerBalance / hrmData.Count ).toFixed(2) + '</div>';

    // text += '<div> The version is : ' + hrmData.Version + '</div>';

    // text += '<div> Array : ';

    // _.each(hrmData.TestArray, function(item){
    //     text += item + ', ';

    // });

    // text += '</div>';


    // text += '<div> Array : ';

    // _.each(hrmData.HeartRateData, function(item){
    //     text += item + ' | ';

    // });

    // text += '</div>';


    // text += '<div> Array : ';

    // _.each(hrmData.SpeedData, function(item){
    //     text += item + ' | ';

    // });

    // text += '</div>';
    // text += '<div> Array : ';

    // _.each(hrmData.CadanceData, function(item){
    //     text += item + ' | ';

    // });

    // text += '</div>';
    // text += '<div> Array : ';

    // _.each(hrmData.AltitudeData, function(item){
    //     text += item + ' | ';

    // });

    // text += '</div>';
    // text += '<div> Array : ';

    // _.each(hrmData.PowerData, function(item){
    //     text += item + ' | ';

    // });

    // text += '</div>';
    // text += '<div> Array : ';

    // _.each(hrmData.PowerBalanceData, function(item){
    //     text += item + ' | ';

    // });

    // text += '</div>';





    // document.getElementById('main').innerHTML += text;

    callback(hrmData);

    //return hrmData;
};
