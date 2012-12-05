
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


//_ret := json

? "------------------------------------------"
? "harbour echo_json ce vratiti:" 
? pp(_ret)
? "------------------------------------------"
return  _ret
