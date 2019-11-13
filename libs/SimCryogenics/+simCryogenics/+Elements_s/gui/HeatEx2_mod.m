function guiinfo = HeatEx2_mod ()

    guiinfo = [];

    guiinfo.blocksize.width = 80;
    guiinfo.blocksize.height = 150;

    %guiinfo.paramorder = {};

    guiinfo.tabs{1}.Label = 'Geometry';
    guiinfo.tabs{1}.Items = {'N','Vh','Vc','M','Kh','Kc','hhn','hcn','ex_mode'};

    guiinfo.tabs{2}.Label = 'Initial conditions';
    guiinfo.tabs{2}.Items = {'Ph0','Th0','Pc0','Tc0','Mh0','Mc0'};
    
    guiinfo.tabs{3}.Label = 'Nominal conditions';
    guiinfo.tabs{3}.Items = {'Phn','Thn','Pcn','Tcn','Mhn','Mcn'};
    
    guiinfo.combos.ex_mode.Entries = {'constant h','sqrt formula','complex formula'};
    guiinfo.combos.ex_mode.Values = [0 1 2];
    guiinfo.combos.ex_mode.MapValues = {'0' '1' '2'};
    guiinfo.combos.ex_mode.Callback = '';
end


