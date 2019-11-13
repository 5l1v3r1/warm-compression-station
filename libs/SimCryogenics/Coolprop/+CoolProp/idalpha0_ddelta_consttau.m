function v = idalpha0_ddelta_consttau()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 55);
  end
  v = vInitialized;
end
