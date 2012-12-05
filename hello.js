var addon = require('./build/Release/hello')

var counter = 0;


var _connection_params = { "host": "localhost", "user" : "test1", "password": "test1", "port": 5432, "database": "f18_test", "schema": "fmk" }
var rezultat_string = addon.eval_json("{\"eval\": \"server_info\", \"args\": " + JSON.stringify(_connection_params) + " }");
var rezultat = JSON.parse(rezultat_string);
console.log("addon vration json string: " + rezultat_string + " evo server_version vrijednosti: " + rezultat.server_version);


console.log("------------------- idemo dalje ----------");

setInterval(function() {

  for(var i=1; i<1000; i++)
  {
    console.log("--------------------------------------------");
    console.log("idemo put:" + i + "  / " +  counter );

    //console.log(addon.hello());
    var rezultat_string = addon.eval_json("{\"eval\": \"+\", \"args\": [1, "+ i +"] }");
    var rezultat = JSON.parse(rezultat_string);
    console.log("addon vration json string: " + rezultat_string + " evo ret vrijednosti: " + rezultat.ret);
  
  }
  ++counter;

  if (counter > 300) {
      console.log("dosta vise vrcenja ...");
      process.exit(code=0);
  }

}, 300);

console.log("hej ovo fakat radi :)");


