CONST MAXN=200;
      FI='SUBSTR13.INP';
      FO='SUBSTR13.OUT';
TYPE TARR = ARRAY[0 .. MAXN+1, 'a'..'z'] OF LONGINT;
VAR F:ARRAY[0..MAXN, 0..MAXN, 0..MAXN] OF INT64;
    NHAYX,NHAYY:TARR;
    I,M,N,K,A,B:LONGINT;
    TMP,KQ:INT64;
    X,Y,S:STRING;
    F1,F2:TEXT;
//-----------------------
PROCEDURE MAKENHAY(VAR NEXT:TARR;NB:LONGINT;B:STRING);
VAR C:CHAR;
    J:LONGINT;
BEGIN
    FILLCHAR(NEXT,SIZEOF(NEXT),0);
    FOR C:='a' TO 'z' DO
        BEGIN
            NEXT[NB,C]:=NB+1;NEXT[NB+1,C]:=NB+1;
            FOR J:=NB-1 DOWNTO 0 DO
                IF B[J+1]=C THEN NEXT[J,C]:=J+1
                ELSE NEXT[J,C]:=NEXT[J+1,C];
        END;
END;
//-------------------------
FUNCTION TINH(I,VTX,VTY:LONGINT):INT64;
VAR V:CHAR;
    DEM:INT64;
    J:BYTE;
BEGIN
    IF F[I,VTX,VTY] >- 1 THEN EXIT(F[I,VTX,VTY]);
    IF I>N THEN EXIT(ORD((VTX <= LENGTH(X)) AND (VTY = LENGTH(Y)+1)));
    DEM:=0;
    FOR V:='a' TO 'z' DO
        DEM := (DEM+TINH(I+1,NHAYX[VTX,V],NHAYY[VTY,V])) MOD K;
    F[I, VTX, VTY] := DEM;
    EXIT(DEM);
END;
//-------------------------
PROCEDURE TIMKQ(I,VTX,VTY:LONGINT);//S[i], VtX, VtY
VAR V:CHAR;
    C:INT64;
BEGIN
    IF I>N THEN
        BEGIN
            IF NOT((VTX <= LENGTH(X))AND(VTY = LENGTH(Y)+1)) THEN KQ:=-1;
            EXIT;
        END;
    FOR V:='a' TO S[I] DO
        BEGIN
            C:=TINH(I+1, NHAYX[VTX,V], NHAYY[VTY,V]);
            IF V < S[I] THEN KQ := (KQ+C) MOD K
            ELSE TIMKQ(I+1, NHAYX[VTX, V], NHAYY[VTY, V]);
        END;
END;
//----------------------------
BEGIN
    ASSIGN(F1,FI);RESET(F1);
    ASSIGN(F2,FO);REWRITE(F2);
    READLN(F1,M,N,K);
    READLN(F1,X);READLN(F1,Y);A:=LENGTH(X);B:=LENGTH(Y);
    MAKENHAY(NHAYX, A, X);MAKENHAY(NHAYY, B, Y);
    FILLCHAR(F, SIZEOF(F), 255);
    TMP:=TINH(1, 0, 0);//
    FOR I:=1 TO M DO
        BEGIN
            READLN(F1, S);
            KQ := 0;
		TIMKQ(1, 0, 0);
            IF KQ>-1 THEN KQ:=(KQ+1) MOD K;
            WRITELN(F2,KQ);
        END;
    CLOSE(F1);CLOSE(F2);
END.