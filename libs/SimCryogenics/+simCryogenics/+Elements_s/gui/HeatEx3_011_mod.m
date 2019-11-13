function guiinfo = HeatEx3_011_mod ()

    guiinfo = [];

    guiinfo.blocksize.width = 80;
    guiinfo.blocksize.height = 150;

    % guiinfo.paramorder = {};

    guiinfo.tabs{1}.Label = 'Geometry';
    guiinfo.tabs{1}.Items = {'N','Vh','Vm','Vc','M','Kh','Km','Kc'};

    guiinfo.tabs{2}.Label = 'Initial conditions';
    guiinfo.tabs{2}.Items = {'Ph0','Th0','Pm0','Tm0','Pc0','Tc0','Mh0','Mm0','Mc0'};
    
    guiinfo.tabs{3}.Label = 'Nominal conditions';
    guiinfo.tabs{3}.Items = {'Phn','Thn','Mhn','Pmn','Tmn','Mmn','Pcn','Tcn','Mcn'};
    
    guiinfo.tabs{4}.Label = 'Heat exchange setup';
    guiinfo.tabs{4}.Items = {'hn_h','hn_m','hn_c','ex_hp_bp','ex_hp_mp','ex_mp_bp'};
    
    guiinfo.combos.ex_mode.Entries = {'constant h','sqrt formula','complex formula'};
    guiinfo.combos.ex_mode.Values = [0 1 2];
    guiinfo.combos.ex_mode.MapValues = {'0' '1' '2'};
    guiinfo.combos.ex_mode.Callback = '';
    
end