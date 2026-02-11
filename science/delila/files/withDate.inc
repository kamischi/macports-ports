type
  DateString = datetimearray;

procedure date(var adatetime: datetimearray; Format: DateString); overload;
var
  output: DateString;
  i: 1..datetimearraylength + 1;
  j: 1..maxint;
  MyTS: TimeStamp;
  YearString:   packed array[1..4] of char;
  MonthString:  packed array[1..2] of char;
  DayString:    packed array[1..2] of char;
  HourString:   packed array[1..2] of char;
  MinuteString: packed array[1..2] of char;
  SecondString: packed array[1..2] of char;
begin
  GetTimeStamp(MyTS);
  YearString[1]   := char(ord('0') +  MyTS.year   div 1000);
  YearString[2]   := char(ord('0') + (MyTS.year   div 100) mod 10);
  YearString[3]   := char(ord('0') + (MyTS.year   div 10 ) mod 10);
  YearString[4]   := char(ord('0') +  MyTS.year   mod 10);
  MonthString[1]  := char(ord('0') +  MyTS.month  div 10);
  MonthString[2]  := char(ord('0') +  MyTS.month  mod 10);
  DayString[1]    := char(ord('0') +  MyTS.day    div 10);
  DayString[2]    := char(ord('0') +  MyTS.day    mod 10);
  HourString[1]   := char(ord('0') +  MyTS.hour   div 10);
  HourString[2]   := char(ord('0') +  MyTS.hour   mod 10);
  MinuteString[1] := char(ord('0') +  MyTS.minute div 10);
  MinuteString[2] := char(ord('0') +  MyTS.minute mod 10);
  SecondString[1] := char(ord('0') +  MyTS.second div 10);
  SecondString[2] := char(ord('0') +  MyTS.second mod 10);
  i := 1;
  j := 1;
  repeat
    if Format[i] <> '%' then
      adatetime[j] := Format[i]
    else
    begin
      system.inc(i);
      case Format[i] of
        'Y': begin
               adatetime[j]   := YearString[1];
               adatetime[j+1] := YearString[2];
               adatetime[j+2] := YearString[3];
               adatetime[j+3] := YearString[4];
               system.inc(j, 4);
             end;
        'm': begin
               adatetime[j]   := MonthString[1];
               adatetime[j+1] := MonthString[2];
               system.inc(j, 2);
             end;
        'd': begin
               adatetime[j]   := DayString[1];
               adatetime[j+1] := DayString[2];
               system.inc(j, 2);
             end;
        'H': begin
               adatetime[j]   := HourString[1];
               adatetime[j+1] := HourString[2];
               system.inc(j, 2);
             end;
        'M': begin
               adatetime[j]   := MinuteString[1];
               adatetime[j+1] := MinuteString[2];
               system.inc(j, 2);
             end;
        'S': begin
               adatetime[j]   := SecondString[1];
               adatetime[j+1] := SecondString[2];
               system.inc(j, 2);
             end;
      end;
    end;
    system.inc(i);
    system.inc(j);
  until i > datetimearraylength;
end;

procedure date(var adatetime: datetimearray); overload;
begin
  date(adatetime, '%Y/%m/%d');
end;

procedure time(var adatetime: datetimearray);
begin
  date(adatetime, '%H:%M:%S');
end;