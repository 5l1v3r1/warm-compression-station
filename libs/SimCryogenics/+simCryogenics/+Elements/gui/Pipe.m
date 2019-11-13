function guiinfo = Pipe ()

    guiinfo = [];

    guiinfo.blocksize.width = 70;
    guiinfo.blocksize.height = 30;

    %guiinfo.paramorder = {};

    guiinfo.tabs{1}.Label = 'Main';
    guiinfo.tabs{1}.Items = {'Vol','P0','T0','Ideal'};

    guiinfo.combos.Ideal.Entries = {'derivation of P','derivation of rho and u'};
    guiinfo.combos.Ideal.Values = [1 0];
    guiinfo.combos.Ideal.MapValues = {'1' '0'};
    guiinfo.combos.Ideal.Callback = '';

end