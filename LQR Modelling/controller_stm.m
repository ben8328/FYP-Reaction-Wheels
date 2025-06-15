function u=controller_stm(in,s)

x1=in(1);
x2=in(2);
x3=in(3);
x4=in(4);
x5=in(5);
x6=in(6);
x7=in(7);
x8=in(8);

%% Create the messages
m1=sprintf('ctrl set x1 %f',x1);
m2=sprintf('ctrl set x2 %f',x2);
m3=sprintf('ctrl set x3 %f',x3);
m4=sprintf('ctrl set x4 %f',x4);
m5=sprintf('ctrl set x5 %f',x5);
m6=sprintf('ctrl set x6 %f',x6);
m7=sprintf('ctrl set x7 %f',x7);
m8=sprintf('ctrl set x8 %f',x8);
cmd1='ctrl get u1';
cmd2='ctrl get u2';
cmd3='ctrl get u3';

%% Send message to the serial connection s (STM)
writeline(s,m1);        % send 'ctrl set x1 x1_value'
writeline(s,m2);        % send 'ctrl set x2 x2_value'
writeline(s,m3);        % send 'ctrl set x3 x3_value'
writeline(s,m4);        % send 'ctrl set x4 x4_value'
writeline(s,m5);        % send 'ctrl set x5 x5_value'
writeline(s,m6);        % send 'ctrl set x6 x6_value'
writeline(s,m7);        % send 'ctrl set x7 x7_value'
writeline(s,m8);        % send 'ctrl set x8 x8_value'

writeline(s,cmd1);       % send 'ctrl get u1'
res1=readline(s);        % read the output in stm buffer, that is the result of sum
u1=str2double(res1); % convert result 'res' from string to a double precision value


writeline(s,cmd2);       % send 'ctrl get u2'
res2=readline(s);        % read the output in stm buffer, that is the result of sum
u2=str2double(res2); % convert result 'res' from string to a double precision value


writeline(s,cmd3);       % send 'ctrl get u3'
res3=readline(s);        % read the output in stm buffer, that is the result of sum
u3=str2double(res3); % convert result 'res' from string to a double precision value


u=[u1 u2 u3];
%%
end
