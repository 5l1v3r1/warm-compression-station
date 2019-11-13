function v = idalphar_ddelta_consttau()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 52);
  end
  v = vInitialized;
end
