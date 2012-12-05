
procedure echo_json_0()
local _ret

_ret := "[a:1]" 

? "harbour treba vratiti:" + _ret

return _ret

function echo_json(json)
local _i
local _ret
local _json2

json := pp(json)
? "harbour echo_json je primila string:" + json

_json2 := STRTRAN(json, "a", "b") 
_json2 := STRTRAN(_json2, "1", "101") 

_ret := ""
for _i :=  1 to 1000
  if _i > 1
      _ret += " , "
  endif
  _ret +=  "{ par" + alltrim(str(_i)) + ":" + json + " , { p2" + alltrim(str(_i))+  ": " +  _json2 + "}"
next
_ret := "[ " + _ret + " ]"


? "------------------------------------------"
? "harbour echo_json ce vratiti:" 
? pp(_ret)
? "------------------------------------------"
return  _ret


function eval_json(json) 
local _var, _json_len
local _ret := hb_hash()
local _op, _args

/*
{  eval: +
   args: [1, 2]
} 

=>

{
   rez: 3
}
*/
? "----------- start harbour eval_json ---------"
? "json:", pp(json)

_json_len := hb_jsonDecode(json, @_var)

? "harour var:", pp(_var)

if hb_HHASKEY(_var, "eval")
  _op := _var["eval"]
else
  return nil
endif

if hb_HHASKEY(_var, "args")
  _args := _var["args"]
else
  return nil
endif

if (_op == "+")
   if VALTYPE(_args) == "A"
       _ret["ret"] := _args[1] + _args[2]
   endif
endif

if (_op == "-")
   if VALTYPE(_args) == "A"
       _ret["ret"] := _args[1] - _args[2]
   endif
endif

if (_op == "server_info")

  // parametri konekcije na server
  ? "server_info parametri", pp(_args)

  f18_set_server_params(_args)

  f18_init_app()
  _ret := server_info()
endif


? "harbour ret", pp(_ret)
_ret := hb_jsonEncode(_ret)
? "json encoded: valtype",  valtype(_ret),  pp(_ret)
? "------- harbour eval_json end ----------"
?
return _ret

procedure main()
? "dummy main"
return



// ----------------------------------------------------
// ----------------------------------------------------
function server_info()
local _key
local _server_vars := {"server_version", "TimeZone"}
local _sys_info
local _ret := hb_hash()

for each _key in _server_vars 
  _ret[LOWER(_key)] := server_show(_key)
next

_sys_info := server_sys_info()

if _sys_info != NIL
    for each _key in _sys_info:Keys
        _ret[LOWER(_key)] :=  _sys_info[_key]
    next
endif

return _ret


