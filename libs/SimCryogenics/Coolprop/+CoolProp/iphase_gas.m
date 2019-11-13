function v = iphase_gas()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 79);
  end
  v = vInitialized;
end
