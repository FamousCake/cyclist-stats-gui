var addon = require('bindings')('addon.node');

var gosho = addon('Gosho', 4234);

document.getElementById('main').innerHTML += gosho.name + ' / ' + (gosho.age/2);


