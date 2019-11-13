function v = iCvirial()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 57);
  end
  v = vInitialized;
end
