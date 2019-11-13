function v = iT_freeze()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 64);
  end
  v = vInitialized;
end
