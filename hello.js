var addon = require('./build/Release/hello')


for(var i=1; i<10; i++)
{
  console.log("idemo put:" + i);

  //console.log(addon.hello());
  console.log("hello.js vraca iz hello.cc: " + addon.hello2());
}

console.log("hej ovo fakat radi :)");


