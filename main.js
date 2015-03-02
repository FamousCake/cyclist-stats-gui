var addon = require('bindings')('addon.node');
var _ = require('underscore');


var gosho = addon();

var text = '';

for(var p in gosho){
    text += '<div>' + p + ' : ' + (gosho[p] / gosho.Count) + '</div>';
}

document.getElementById('main').innerHTML += text;


