TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM PLC_PRG
  VAR
    Sensor_X AT %IX0.0 : BOOL;
    Sensor_Y AT %IX0.1 : BOOL;
    LED_Amarillo AT %QX0.0 : BOOL;
    LED_Rojo AT %QX0.1 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    TON2 : TON;
  END_VAR

  TON0(IN := Sensor_X OR Sensor_Y, PT := t#5s);
  LED_Amarillo := TON0.Q;
  TON2(IN := TON0.Q, PT := t#10s);
  LED_Rojo := TON2.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : PLC_PRG;
  END_RESOURCE
END_CONFIGURATION
