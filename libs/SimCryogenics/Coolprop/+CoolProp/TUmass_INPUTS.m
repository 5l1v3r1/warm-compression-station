function v = TUmass_INPUTS()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 109);
  end
  v = vInitialized;
end