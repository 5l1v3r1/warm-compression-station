function v = iCpmolar()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 29);
  end
  v = vInitialized;
end
