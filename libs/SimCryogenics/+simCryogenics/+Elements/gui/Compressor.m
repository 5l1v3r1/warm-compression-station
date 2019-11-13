function guiinfo = Compressor ()

  guiinfo = [];
  
  guiinfo.blocksize.width = 70;
  guiinfo.blocksize.height = 70;
  
  %guiinfo.paramorder = {};
 
  guiinfo.tabs{1}.Label = 'Parameters';
  guiinfo.tabs{1}.Items = {'Kc'};
  
  guiinfo.tabs{2}.Label = 'Calculation';
  guiinfo.tabs{2}.Items = {'lin_v','vol','Pnom'};
  
  guiinfo.combos.lin_v.Entries = {'Use classical formula','Treat input as flowrate'};
  guiinfo.combos.lin_v.Values = [0 1];
  guiinfo.combos.lin_v.MapValues = {'0' '1'};
  guiinfo.combos.lin_v.Callback = '';
  
  guiinfo.combos.vol.Entries = {'Use input as it is','Use input time pressure'};
  guiinfo.combos.vol.Values = [0 1];
  guiinfo.combos.vol.MapValues = {'0' '1'};
  guiinfo.combos.vol.Callback = '';
  
  guiinfo.tabs{3}.Label = 'Constraints';
  guiinfo.tabs{3}.Items = {'ControlInputMin','ControlInputMax'};
  

     
end