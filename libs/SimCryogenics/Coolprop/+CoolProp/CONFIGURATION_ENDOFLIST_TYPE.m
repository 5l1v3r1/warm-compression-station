function v = CONFIGURATION_ENDOFLIST_TYPE()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 140);
  end
  v = vInitialized;
end
