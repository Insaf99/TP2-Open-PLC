void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PLC_PRG_init__(PLC_PRG *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_0,data__->SENSOR_X,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR_X,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1,data__->SENSOR_Y,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR_Y,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_0,data__->LED_AMARILLO,retain)
  __INIT_LOCATED_VALUE(data__->LED_AMARILLO,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1,data__->LED_ROJO,retain)
  __INIT_LOCATED_VALUE(data__->LED_ROJO,__BOOL_LITERAL(FALSE))
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON2,retain);
}

// Code part
void PLC_PRG_body__(PLC_PRG *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,IN,,(__GET_LOCATED(data__->SENSOR_X,) || __GET_LOCATED(data__->SENSOR_Y,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_LOCATED(data__->,LED_AMARILLO,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 0, 10, 0, 0, 0));
  TON_body__(&data__->TON2);
  __SET_LOCATED(data__->,LED_ROJO,,__GET_VAR(data__->TON2.Q,));

  goto __end;

__end:
  return;
} // PLC_PRG_body__() 





