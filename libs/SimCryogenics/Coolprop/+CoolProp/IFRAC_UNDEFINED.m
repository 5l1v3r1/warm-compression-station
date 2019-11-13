function v = IFRAC_UNDEFINED()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 86);
  end
  v = vInitialized;
end
