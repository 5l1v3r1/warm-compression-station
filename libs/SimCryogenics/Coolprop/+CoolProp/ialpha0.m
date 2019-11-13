function v = ialpha0()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 53);
  end
  v = vInitialized;
end
