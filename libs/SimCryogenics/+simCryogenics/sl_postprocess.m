function sl_postprocess(h)

LIBRARYNAME = 'simCryogenics_lib';

    ELEMENTS = '/Elements';

%         COMPRESSOR        = '/Compressor';
%         compressor(strcat(LIBRARYNAME,ELEMENTS,COMPRESSOR))
% 
%         DISTRIBUTOR2      = '/Distributor2';
%         distributor2(strcat(LIBRARYNAME,ELEMENTS,DISTRIBUTOR2))
% 
%         DISTRIBUTOR3      = '/Distributor3';
%         distributor3(strcat(LIBRARYNAME,ELEMENTS,DISTRIBUTOR3))
% 
%         DISTRIBUTOR4      = '/Distributor4';
%         distributor4(strcat(LIBRARYNAME,ELEMENTS,DISTRIBUTOR4))
% 
%         PIPE              = '/Pipe';
%         pipe(strcat(LIBRARYNAME,ELEMENTS,PIPE))
% 
%         MIXER2            = '/Mixer2';
%         mixer2(strcat(LIBRARYNAME,ELEMENTS,MIXER2))
% 
%         MIXER3            = '/Mixer3';
%         mixer3(strcat(LIBRARYNAME,ELEMENTS,MIXER3))
% 
%         MIXER4            = '/Mixer4';
%         mixer4(strcat(LIBRARYNAME,ELEMENTS,MIXER4))
% 
%         VALVE             = '/Valve';
%         valve(strcat(LIBRARYNAME,ELEMENTS,VALVE))
% 
%         VALVEONOFF        = '/Valve_ON_OFF';
%         valvetor(strcat(LIBRARYNAME,ELEMENTS,VALVEONOFF))
% 
%         TURBINE_p         = '/Turbine_p';
%         %turbine_p(strcat(LIBRARYNAME,ELEMENTS,TURBINE_p))
%  
%         HEATEX2            = '/HX2';
%         heatex2(strcat(LIBRARYNAME,ELEMENTS,HEATEX2))
%         
%         HEATEX3_011            = '/HX3_011';
%         heatex3(strcat(LIBRARYNAME,ELEMENTS,HEATEX3_011))
% 
%         HEATEX4_0011            = '/HX4_0011';
%         heatex4(strcat(LIBRARYNAME,ELEMENTS,HEATEX4_0011 ))
%         
%         PHASESEPARATOR    = '/PhaseSep';
%         phasesep(strcat(LIBRARYNAME,ELEMENTS,PHASESEPARATOR))
%         
%         PHASESEPARATORH   = '/PhaseSepOp';
%         phaseseph(strcat(LIBRARYNAME,ELEMENTS,PHASESEPARATORH))
% 
%         COLD_COMP_PERF_VOL    = '/Cold_comp_perf_volum';
%         cold_comp_perf(strcat(LIBRARYNAME,ELEMENTS,COLD_COMP_PERF_VOL));

    SENSORS = '/Sensors';
%         F_TRANSMITTER = '/FT';
%         ftrans(strcat(LIBRARYNAME,SENSORS,F_TRANSMITTER))
%         
%         P_TRANSMITTER = '/PT';
%         ptrans(strcat(LIBRARYNAME,SENSORS,P_TRANSMITTER))
% 
%         T_TRANSMITTER = '/TT';
%         ttrans(strcat(LIBRARYNAME,SENSORS,T_TRANSMITTER))
%         
%         PTT_TRANSMITTER = '/PTT';
%         pttrans(strcat(LIBRARYNAME,SENSORS,PTT_TRANSMITTER))
%         
%         PTFT_TRANSMITTER = '/PTFT';
%         ptftrans(strcat(LIBRARYNAME,SENSORS,PTFT_TRANSMITTER))
%         
%         TFT_TRANSMITTER = '/TFT';
%         tftrans(strcat(LIBRARYNAME,SENSORS,TFT_TRANSMITTER))
%         
%         PFT_TRANSMITTER = '/PFT';
%         pftrans(strcat(LIBRARYNAME,SENSORS,PFT_TRANSMITTER))
%         
%         X_TRANSMITTER = '/XT';
%         xtrans(strcat(LIBRARYNAME,SENSORS,X_TRANSMITTER))

    SOURCESSINKS = '/Sources_Sinks';
%         M_CTRL_SRC   = '/M ctrl src';
%         m_ct_scr(strcat(LIBRARYNAME,SOURCESSINKS,M_CTRL_SRC))
% 
%         M_SRC        = '/M src';
%         m_scr(strcat(LIBRARYNAME,SOURCESSINKS,M_SRC))
% 
%         M_T_CTRL_SRC = '/M//T ctrl src';
%         mt_ct_scr(strcat(LIBRARYNAME,SOURCESSINKS,M_T_CTRL_SRC))
% 
%         M_T_SRC      = '/M//T src';
%         mt_scr(strcat(LIBRARYNAME,SOURCESSINKS,M_T_SRC))
% 
%         P_CTRL_SNK   = '/P ctrl snk';
%         p_ct_scr(strcat(LIBRARYNAME,SOURCESSINKS,P_CTRL_SNK))
% 
%         P_SNK        = '/P snk';
%         p_snk(strcat(LIBRARYNAME,SOURCESSINKS,P_SNK))
% 
%         P_T_CTRL_SRC = '/P//T ctrl src';
%         pt_ct_scr(strcat(LIBRARYNAME,SOURCESSINKS,P_T_CTRL_SRC))
% 
%         P_T_SRC      = '/P//T src';
%         pt_scr(strcat(LIBRARYNAME,SOURCESSINKS,P_T_SRC))

    UTILITIES   = '/Utilities';
%         PRESSUREDROP    = '/Pressure drop';
%         prs_drp(strcat(LIBRARYNAME,UTILITIES,PRESSUREDROP))
% 
%         HEATLOAD        = '/Heat load';
%         heat_ld(strcat(LIBRARYNAME,UTILITIES,HEATLOAD))
%         
%         N2_PRPTS        = '/N2_prpts';
%         n2prp(strcat(LIBRARYNAME,UTILITIES,N2_PRPTS))
% 
%         HE_PRPTS        = '/He_prpts';
%         heprp(strcat(LIBRARYNAME,UTILITIES,HE_PRPTS))
%         
%         PRESSURE_LOSS  = '/Pressure loss';
%         prs_lss(strcat(LIBRARYNAME,UTILITIES,PRESSURE_LOSS))
% 
%         COOLER          ='/Cooler';
%         coolr(strcat(LIBRARYNAME,UTILITIES,COOLER))

    % Set the size of the subdirectory of the library
    blockPath = strcat(LIBRARYNAME,ELEMENTS);
    set_param(blockPath,'Position',[10 10 138 138]);
    blockPath = strcat(LIBRARYNAME,SENSORS);
    set_param(blockPath,'Position',[210 10 338 138]);
    blockPath = strcat(LIBRARYNAME,SOURCESSINKS);
    set_param(blockPath,'Position',[410 10 538 138]);
    blockPath = strcat(LIBRARYNAME,UTILITIES);
    set_param(blockPath,'Position',[610 10 738 138]);
    
    blk = find_system('simCryogenics_lib/Sources_Sinks');
    for i=1:length(blk)-1
        a1 = 60+mod(i-1,5)*120;
        b1 = floor((i-1)/5)*120;
        
        set_param(blk{i+1},'Position',[a1 b1 a1+60 b1+60]);
    end
    
    blk = find_system('simCryogenics_lib/Sensors');
    for i=1:length(blk)-1
        a1 = 60+mod(i-1,5)*120;
        b1 = floor((i-1)/5)*120;
        
        set_param(blk{i+1},'Position',[a1 b1 a1+60 b1+60]);
    end

end

function turbine_p(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
end

function turbine(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
end

function compressor(blockPath)
    Mask = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
end

function cold_comp_perf(blockPath)
    Mask = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
    Mask.IconRotate = 'on';
    Mask.RunInitForIconRedraw = 'on';
    
end

function distributor2 (blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
end

function distributor3(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
end

function distributor4(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
end

function mixer2(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
end

function mixer3(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
end

function mixer4(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
end

function pipe(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.IconRotate = 'on';
    Mask.PortRotate = 'physical';
end

function valvetor(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.IconRotate = 'on';
    Mask.PortRotate = 'physical';
end

function valve(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits  = 'normalized';
    Mask.IconFrame  = 'off';
    Mask.IconRotate = 'on';
    Mask.PortRotate = 'physical';
end

function heatex2(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits  = 'normalized';
    Mask.IconFrame  = 'off';
    Mask.IconRotate = 'on';
    Mask.PortRotate = 'physical';
    Mask.RunInitForIconRedraw = 'on';
end

function heatex3(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits  = 'normalized';
    Mask.IconFrame  = 'off';
    Mask.IconRotate = 'on';
    Mask.PortRotate = 'physical';
    Mask.RunInitForIconRedraw = 'on';
end

function heatex4(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits  = 'normalized';
    Mask.IconFrame  = 'off';
    Mask.IconRotate = 'on';
    Mask.PortRotate = 'physical';
    Mask.RunInitForIconRedraw = 'on';
end

function phasesep(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconRotate = 'on';
    Mask.IconFrame = 'off';
end

function phaseseph(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconRotate = 'on';
    Mask.IconFrame = 'off';
end

function ftrans(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
    Mask.RunInitForIconRedraw = 'on';
end

function ptrans(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
    Mask.RunInitForIconRedraw = 'on';
end

function ttrans(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
    Mask.RunInitForIconRedraw = 'on';
end

function pttrans(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
    Mask.RunInitForIconRedraw = 'on';
end

function ptftrans(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
    Mask.RunInitForIconRedraw = 'on';
end

function pftrans(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
    Mask.RunInitForIconRedraw = 'on';
end

function tftrans(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
    Mask.RunInitForIconRedraw = 'on';
end

function xtrans(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.IconFrame = 'off';
    Mask.PortRotate = 'physical';
    Mask.RunInitForIconRedraw = 'on';
end

function str = scr_back1()
    str = strcat(sensor_back1('[0 1 1]'));
end

function str = scr_back2()
    str = sensor_back2();
end

function str = m_scr_back()
    str = flow_back('[1 1 0]');
end

function str = t_scr_back()
    str = temp_back();
end

function str = p_scr_back()
    str = press_back();
end

function m_ct_scr(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconFrame = 'off';
end

function m_scr(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconFrame = 'off';
end

function mt_ct_scr(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconFrame = 'off';
end

function mt_scr(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconFrame = 'off';
end

function pt_ct_scr(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconFrame = 'off';
end

function p_ct_scr(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconFrame = 'off';
end

function p_snk(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconFrame = 'off';
end

function pt_scr(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconFrame = 'off';
end

% utilities 
function prs_drp(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconRotate = 'on';
    Mask.IconFrame = 'off';
end

function heat_ld(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconRotate = 'on';
    Mask.IconFrame = 'off';
end

function n2prp(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconRotate = 'off';
    Mask.IconFrame = 'off';
end

function heprp(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconRotate = 'off';
    Mask.IconFrame = 'off';
end

function prs_lss(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconRotate = 'on';
    Mask.IconFrame = 'off';
end

function coolr(blockPath)
    Mask      = Simulink.Mask.get(blockPath);
    Mask.IconUnits = 'normalized';
    Mask.PortRotate = 'physical';
    Mask.IconRotate = 'on';
    Mask.IconFrame = 'off';
end

function str = sensor_back1(c)
    str = strcat(   't = (0:pi/1000:2*pi);',...
                    'X = 0.5+0.32*cos(t);',...
                    'Y = 0.5+0.32*sin(t);',...
                    'patch(X,Y,',c,');');
end

function str = sensor_back2()
    str = strcat(   't = (0:pi/1000:2*pi);',...
                    'X = 0.5+0.32*cos(t);',...
                    'Y = 0.5+0.32*sin(t);',...
                    'plot(X,Y);');
end

function str = flow_back(c)
    str = strcat(   't = (pi/4:pi/1000:3*pi/4);',...
                    'X = 0.5+0.32*cos(t);',...
                    'Y = 0.5+0.32*sin(t);',...
                    'patch(X,Y,',c,');',...
                    't = (5*pi/4:pi/1000:7*pi/4);',...
                    'X = 0.5+0.35*cos(t);',...
                    'Y = 0.96+0.35*sin(t);',...
                    'patch(X,Y,',c,');',...
                    'plot(X,Y);');
end

function str = press_back()
    str = strcat(   'plot([0.5 0.65],[0.5 0.65]);',...
                    'plot([0.5 1-0.65],[0.5 1-0.65]);',...
                    'plot([0.56 0.65],[0.623 0.65]);',...
                    'plot([0.62 0.65],[0.54 0.65]);');
end

function str = temp_back()
    str = strcat(	'patch([0.48 0.48 0.52 0.52],[0.3 0.7 0.7 0.3],[0 0 0]);',...
                    't = (0:pi/1000:2*pi);',...
                    'X = 0.5+0.04*cos(t);',...
                    'Y = 0.325+0.034*sin(t);',...
                    'patch(X,Y,[0 0 0]);');
end

