function guiinfo = PhaseSepOp ()
    guiinfo = [];

    guiinfo.blocksize.width = 80;
    guiinfo.blocksize.height = 150;

    % guiinfo.paramorder = {};
 
    guiinfo.tabs{1}.Label = 'Geometry';
    guiinfo.tabs{1}.Items = {'hmax','S','h0'};

    guiinfo.tabs{2}.Label = 'First serpentin';
    guiinfo.tabs{2}.Items = {'DeltaT1'};
    
	guiinfo.tabs{3}.Label = 'Second serpentin';
    guiinfo.tabs{3}.Items = {'DeltaT2'};
end


