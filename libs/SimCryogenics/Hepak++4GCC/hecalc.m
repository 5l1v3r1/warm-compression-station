function X = hecalc(Index,Phase,Input1,Value1,Input2,Value2,Unit)
%%HECALC  Calls hecalc routine in Matlab

JPRECS = 2;
JOUT = 11111;
if ischar(Input1),
	if strcmpi(Input1,'SL'),
		Input1 = 13;
	elseif strcmpi(Input1,'SV'),
		Input1 = 14;
	elseif strcmpi(Input1,'P'),
		Input1 = 1;
	elseif strcmpi(Input1,'T'),
		Input1 = 2;
	end
end

if ischar(Input2),
	if strcmpi(Input2,'SL'),
		Input2 = 13;
	elseif strcmpi(Input2,'SV'),
		Input2 = 14;
	elseif strcmpi(Input2,'P'),
		Input2 = 1;
	elseif strcmpi(Input2,'T'),
		Input2 = 2;
	end
end

Input1 = corr_ind( Input1 );
Input2 = corr_ind( Input2 );

X = hecalc_C(JOUT,Input1,Value1,Input2,Value2,JPRECS,Unit,Index); 



