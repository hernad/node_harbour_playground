//var addon = require('./hello')
var addon = require('./build/Release/hello')

var counter = 0;

console.log("start");

console.log(addon.hello());
console.log("prije json");
console.log(addon.echo_json("test"));

console.log("kraj");


