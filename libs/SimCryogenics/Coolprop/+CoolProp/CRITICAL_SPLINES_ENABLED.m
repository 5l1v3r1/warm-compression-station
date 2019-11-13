function v = CRITICAL_SPLINES_ENABLED()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 130);
  end
  v = vInitialized;
end
