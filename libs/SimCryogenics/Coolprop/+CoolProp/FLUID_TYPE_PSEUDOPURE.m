function v = FLUID_TYPE_PSEUDOPURE()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 89);
  end
  v = vInitialized;
end
