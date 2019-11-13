function guiinfo = regul()

    guiinfo = [];
    
    guiinfo.combos.ctrl_type.Entries = {'P','PI'};
    guiinfo.combos.ctrl_type.Values = [0 1];
    guiinfo.combos.ctrl_type.MapValues = {'0' '1'};
    guiinfo.combos.ctrl_type.Callback = '';
    
end