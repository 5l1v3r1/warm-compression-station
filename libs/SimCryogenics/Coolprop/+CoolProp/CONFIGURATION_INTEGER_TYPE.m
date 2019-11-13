function v = CONFIGURATION_INTEGER_TYPE()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 138);
  end
  v = vInitialized;
end
