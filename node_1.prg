
procedure echo_json_0()
local _ret

_ret := "[a:1]" 

? "harbour treba vratiti:" + _ret

return

function echo_json(json)
local _ret

_ret := STRTRAN(json, "a", "b") 
_ret := STRTRAN(_ret, "1", "101") 

return  _ret

