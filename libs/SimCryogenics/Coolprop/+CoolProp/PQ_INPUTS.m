function v = PQ_INPUTS()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 96);
  end
  v = vInitialized;
end
