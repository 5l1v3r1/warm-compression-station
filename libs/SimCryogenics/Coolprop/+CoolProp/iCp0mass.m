function v = iCp0mass()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 38);
  end
  v = vInitialized;
end
