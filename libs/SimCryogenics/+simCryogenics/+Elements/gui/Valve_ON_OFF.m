function guiinfo = Valve_ON_OFF ()

    guiinfo = [];

    guiinfo.blocksize.width = 90;
    guiinfo.blocksize.height = 60;

    %guiinfo.paramorder = {};

    guiinfo.tabs{1}.Label = 'Geometry';
    guiinfo.tabs{1}.Items = {'CVmax','Rv','Xt'};

    guiinfo.tabs{2}.Label = 'Calculation';
    guiinfo.tabs{2}.Items = {'lin_v','lim_v'};

    guiinfo.combos.lin_v.Entries = {'Use classical formula','Treat input as flowrate'};
    guiinfo.combos.lin_v.Values = [0 1];
    guiinfo.combos.lin_v.MapValues = {'0' '1'};
    guiinfo.combos.lin_v.Callback = '';

    guiinfo.combos.lim_v.Entries = {'on','off'};
    guiinfo.combos.lim_v.Values = [1 0];
    guiinfo.combos.lim_v.MapValues = {'1' '0'};
    guiinfo.combos.lim_v.Callback = '';

    guiinfo.tabs{3}.Label = 'Constraints';
    guiinfo.tabs{3}.Items = {'ControlInputMin','ControlInputMax'};

end