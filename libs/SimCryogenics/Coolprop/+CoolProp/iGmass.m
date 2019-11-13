function v = iGmass()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 41);
  end
  v = vInitialized;
end
