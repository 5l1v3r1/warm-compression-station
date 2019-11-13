function v = FLUID_TYPE_REFPROP()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 90);
  end
  v = vInitialized;
end
