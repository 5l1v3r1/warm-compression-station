function guiinfo = Cold_comp_perf_volum ()

    guiinfo = [];

    guiinfo.blocksize.width = 70;
    guiinfo.blocksize.height = 70;
    
    guiinfo.combos.vol.Entries = {'no','yes'};
    guiinfo.combos.vol.Values = [0 1];
    guiinfo.combos.vol.MapValues = {'0' '1'};
    guiinfo.combos.vol.Callback = '';
    
end