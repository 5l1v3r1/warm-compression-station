function guiinfo = HeatEx3_011 ()

    guiinfo = [];

    guiinfo.blocksize.width = 80;
    guiinfo.blocksize.height = 150;

    % guiinfo.paramorder = {};

    guiinfo.tabs{1}.Label = 'Geometry';
    guiinfo.tabs{1}.Items = {'N','Vh','Vm','Vc','M','Kh','Km','Kc','hh_m','hh_c','hm_c'};

    guiinfo.tabs{2}.Label = 'Initial conditions';
    guiinfo.tabs{2}.Items = {'Ph0','Th0','Pm0','Tm0','Pc0','Tc0','Mh0','Mm0','Mc0'};
    
end