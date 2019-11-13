function guiinfo = HeatEx4_0011 ()

    guiinfo = [];

    guiinfo.blocksize.width = 80;
    guiinfo.blocksize.height = 150;

    % guiinfo.paramorder = {};

    guiinfo.tabs{1}.Label = 'Geometry';
    guiinfo.tabs{1}.Items = {'N','Vh','Vm','Vc','Vvc','M','Kh','Km','Kc','Kvc'};

    guiinfo.tabs{2}.Label = 'Heat exchange coefficients';
    guiinfo.tabs{2}.Items = {'hh_m','hh_c','hh_vc','hm_c','hm_vc','hc_vc'};

    guiinfo.tabs{3}.Label = 'Initial conditions';
    guiinfo.tabs{3}.Items = {'Ph0','Th0','Pm0','Tm0','Pc0','Tc0','Pvc0','Tvc0','Mh0','Mm0','Mc0','Mvc0'};

end

