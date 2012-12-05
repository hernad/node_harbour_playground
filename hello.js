var addon = require('./build/Release/hello')

var counter = 0;

setInterval(function() {

  for(var i=1; i<10000; i++)
  {
    console.log("--------------------------------------------");
    console.log("idemo put:" + i + "  / " +  counter );

    //console.log(addon.hello());
    console.log("hello.js vraca iz hello.cc: " + addon.hello2());
  }

  ++counter;

}, 1000);

console.log("hej ovo fakat radi :)");


