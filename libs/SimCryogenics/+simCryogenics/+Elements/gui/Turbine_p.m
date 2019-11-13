function guiinfo = Turbine_p ()

    guiinfo = [];

    guiinfo.blocksize.width = 90;
    guiinfo.blocksize.height = 40;
    
    %guiinfo.paramorder = {};

    guiinfo.tabs{1}.Label = 'Geometry';
    guiinfo.tabs{1}.Items = {'A','D','Mass'};

    guiinfo.tabs{2}.Label = 'Effciency';
    guiinfo.tabs{2}.Items = {'eta0','cst_eff'};
  
    guiinfo.tabs{3}.Label = 'Nominal conditions';
    guiinfo.tabs{3}.Items = {'Tin0','Pin0','Pout0','N0'};
    
end
