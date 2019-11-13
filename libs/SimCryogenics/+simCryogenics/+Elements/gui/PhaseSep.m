function guiinfo = PhaseSep ()
    guiinfo = [];

    guiinfo.blocksize.width = 80;
    guiinfo.blocksize.height = 150;

    % guiinfo.paramorder = {};
 
    guiinfo.tabs{1}.Label = 'Geometry';
    guiinfo.tabs{1}.Items = {'P0','hmax','S','h0'};

    guiinfo.tabs{2}.Label = 'First serpentin';
    guiinfo.tabs{2}.Items = {'h1','Ideal1','DeltaT1','N1'};
    
	guiinfo.tabs{3}.Label = 'Second serpentin';
    guiinfo.tabs{3}.Items = {'h2','Ideal2','DeltaT2','N2'};
end

