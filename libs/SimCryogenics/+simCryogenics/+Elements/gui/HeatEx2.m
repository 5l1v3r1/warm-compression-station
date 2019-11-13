function guiinfo = HeatEx2 ()

    guiinfo = [];

    guiinfo.blocksize.width = 80;
    guiinfo.blocksize.height = 150;

    %guiinfo.paramorder = {};

    guiinfo.tabs{1}.Label = 'Geometry';
    guiinfo.tabs{1}.Items = {'N','Vh','Vc','M','Kh','Kc','h'};

    guiinfo.tabs{2}.Label = 'Initial conditions';
    guiinfo.tabs{2}.Items = {'Ph0','Th0','Pc0','Tc0','Mh0','Mc0'};
    
end


