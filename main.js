var module = function(filepath) {

    document.getElementById('main').innerHTML = '';

    var addon = require('bindings')('addon.node');
    var _ = require('underscore');

    var gosho = addon(filepath);

    var text = '';

    text += '<div> Average heart rate is : ' + (gosho.HeartRate / gosho.Count).toFixed(2) + ' BPM </div>';
    text += '<div> Average speed is : ' + (gosho.Speed / gosho.Count).toFixed(2) + ' KM/H </div>';
    text += '<div> Average cadence is : ' + (gosho.Cadance / (gosho.Count * 10)).toFixed(2) + ' RPM </div>';

    text += '<div> Average altitude is : ' + (gosho.Altitude / gosho.Count).toFixed(2) + ' feet </div>';
    text += '<div> Average power is : ' + (gosho.Power / gosho.Count).toFixed(2) + ' W </div>';
    text += '<div> Average power balance is : ' + (gosho.PowerBalance / gosho.Count ).toFixed(2) + '</div>';

    text += '<div> The version is : ' + gosho.Version + '</div>';

    text += '<div> Array : ';

    _.each(gosho.TestArray, function(item){
        text += item + ', ';

    });

    text += '</div>';


    text += '<div> Array : ';

    _.each(gosho.HeartRateData, function(item){
        text += item + ' | ';

    });

    text += '</div>';


    text += '<div> Array : ';

    _.each(gosho.SpeedData, function(item){
        text += item + ' | ';

    });

    text += '</div>';
    text += '<div> Array : ';

    _.each(gosho.CadanceData, function(item){
        text += item + ' | ';

    });

    text += '</div>';
    text += '<div> Array : ';

    _.each(gosho.AltitudeData, function(item){
        text += item + ' | ';

    });

    text += '</div>';
    text += '<div> Array : ';

    _.each(gosho.PowerData, function(item){
        text += item + ' | ';

    });

    text += '</div>';
    text += '<div> Array : ';

    _.each(gosho.PowerBalanceData, function(item){
        text += item + ' | ';

    });

    text += '</div>';





    document.getElementById('main').innerHTML += text;

};
